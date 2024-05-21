
// Compilation:
//   g++ ex_11_2_Mandelbrot.cpp EasyBMP.cpp -O2 -std=c++14 -o mandelbrot

#include "EasyBMP.h"
#include <complex>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std;
typedef complex<double> Complex;
/**
 * Returns functional object that converts pixel position to point in the complex plane.
 * @param imageWidth   image width
 * @param imageHeight  image hight
 * @param x1           minimal x
 * @param y1           minimal y
 * @param x2           maximal x
 * @param y2           maximal y
 * @return             functional object
 */
auto scaleFromPixelToComplex(int imageWidth, int imageHeight,
                             double x1, double y1, double x2, double y2){
    double sx = (x2-x1)/imageWidth;
    double sy = (y2-y1)/imageHeight;
    return [=](int x, int y){
        return Complex(x1 + sx * x, y2 - sy * y);
    };
}

/**
 * Checks if given complex number c is in not the Mandelbrot set.
 * @param c complex number
 * @param maxNumberOfIterations  maximal number of iterations
 * @param escapeThreshold
 * @return number of iterations after which image of 0 has module greather
 *         than escapeTreshold or 0 is maxNumberOfIteration was reached.
 */
static auto MandelbrotSetIterations( Complex c,
        size_t maxNumberOfIterations,
        double escapeThreshold = 4.0
){
    Complex x = 0;
    for(int i=0; i<maxNumberOfIterations; i++){
        x = x*x+c;
        if(abs(x)>escapeThreshold)
            return i+1;
    }
    return 0;
}

void computeMandelbrot(BMP& output, auto pixelToComplex, auto iterationsToPixel,
                       int imageWidth, int imageHeight, size_t maxNumberOfIterations,
                       double escapeThreshold, int& index, mutex& indexMutex) {
  while (true) {
    int idx;
    {
      lock_guard<mutex> lock(indexMutex);
      if (index >= imageWidth * imageHeight) {
        break;
      }
      idx = index++;
    }
    int x = idx % imageWidth;
    int y = idx / imageWidth;
    Complex c = pixelToComplex(x, y);
    auto numberOfIterations = MandelbrotSetIterations(c, maxNumberOfIterations, escapeThreshold);
    auto pixel = iterationsToPixel(numberOfIterations);
    output.SetPixel(x, y, pixel);
  }
}

int main( int argc, char* argv[] )
{

    const int imageWidth = 1000;                // bitmap width
    const int imageHeight = 1000;               // bitmap height
    const char * fileName = "mandelbrot.bmp";     // file name to output bitmap

    double x1=-2, x2=1,   // Rectangle in the complex plane [x1, x2]x[y1,,y2]
    y1=-1, y2=1;          // that will plotted on bitmap.

    size_t maxNumberOfIteration = 2000;
    double escapeThreshold = 4;

    BMP Output;                                // We create bitmap
    Output.SetSize(imageWidth, imageHeight );  // We set bitmap sizes
    Output.SetBitDepth( 24 );        // We set color depth
    // Each pixel has 24 bits (8 bits for each RGB component)

    auto pixelToComplex = scaleFromPixelToComplex(imageWidth, imageHeight, x1, y1, x2, y2);

    auto iterationsToPixel = [](size_t numerOfIterations){
        RGBApixel pixel;
        pixel.Blue = 0;
        pixel.Green = (ebmpBYTE) 0;
        pixel.Red = (ebmpBYTE) 0;
        if(numerOfIterations>0){
            pixel.Green = (ebmpBYTE) 255 - 10*(numerOfIterations % 20);
            pixel.Red = (ebmpBYTE) 255 - 10*(numerOfIterations % 10);
        }
        pixel.Alpha = 0;
        return pixel;
    };
  int index = 0;                   // Shared index for pixels
  mutex indexMutex;                // Mutex to protect the shared index
  int numThreads = thread::hardware_concurrency(); // Number of threads to use

  auto start = chrono::steady_clock::now();

  // Create and launch threads
  vector<thread> threads;
  for (int t = 0; t < numThreads; ++t) {
    threads.emplace_back([&] {
      computeMandelbrot(Output, pixelToComplex, iterationsToPixel, imageWidth, imageHeight,
                        maxNumberOfIteration, escapeThreshold, index, indexMutex);
    });
  }


  // Join threads
  for (auto& t : threads) {
    t.join();
  }
//    auto start = std::chrono::steady_clock::now();
//
//    for(unsigned y=0; y<imageHeight; y++){
//        for(unsigned x=0; x<imageWidth; x++){
//
//            Complex c = pixelToComplex(x, y);
//
//            auto numberOfIteration = MandelbrotSetIterations(c, maxNumberOfIteration, escapeThreshold);
//            auto pixel = iterationsToPixel(numberOfIteration);
//            Output.SetPixel(x,y,pixel) ;
//        }
//    }
    auto stop = std::chrono::steady_clock::now();
    cout << "Time used : " << std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count() << " ms."<< endl;
    cout << "Bitmap written to " << fileName << "." << endl;
    Output.WriteToFile( fileName );
    return 0;
}
/*
Time used : 1280 ms.
Bitmap written to mandelbrot.bmp.
*/