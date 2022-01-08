
#ifndef scheduler_h
#define scheduler_h
#include "ofMain.h"

class ofApp;

class Scheduler: public ofThread {
public:
    ofApp* app;
    Scheduler(int nanos, ofApp* anApp);
    void setTimer(int time);
    

private:
    ofTimer timer;
    void threadedFunction();
    

};


#endif /* scheduler_h */
