#include "scheduler.h"
#include "ofApp.h"


Scheduler::Scheduler(int nanos, ofApp* anApp) {
    app = anApp;
    timer.setPeriodicEvent(nanos);
    startThread();
}

void Scheduler::threadedFunction() {
    while(isThreadRunning()) {
         timer.waitNext();
        app->tick();

    }
}

void Scheduler::setTimer(int time) {
    timer.setPeriodicEvent(time);
    
}
    




