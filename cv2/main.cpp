#include "include/demos/Helloworld/helloworld.hpp"
#include "include/demos/Static/Static.hpp"
//#include "include/demos/HSV/hsv.hpp"
#include "include/demos/FaceRecognizer/FaceRecognizer.hpp"
#include "include/demos/RedRecognizer/RedRecognizer.hpp"


int main()
{
    // Helloworld
    //runProject();

    // Static
    //static_treshold_search();

    // HSV
    //runHsv();

    // Red Cup image
    //RedRecognizer recognizer;
    //recognizer.run_static();

    // Red Cup video
    RedRecognizer recognizer;
    recognizer.run_video();

    // Face
    //FaceRecognizer recognizer;
    //// Initialize classifier and camera
    //if (!recognizer.init()) {
    //    std::cerr << "Failed to initialize FaceRecognizer." << std::endl;
    //    return -1;
    //}

    //// Run face detection loop
    //int result = recognizer.run();
    //if (result != 0) {
    //    std::cerr << "FaceRecognizer encountered an error." << std::endl;
    //}

    return 0;
}
