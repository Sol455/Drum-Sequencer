#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "scheduler.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void tick();
        Scheduler* scheduler;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void tempoChanged(float & tempoSlider);
    
        int padding_x;
        int padding_y;
        int cell_width;
        int cell_height;
        int cell_spacing;
        int cell_colour_off;
        int cell_colour_on;
        int background_colour;
        float tempo_input;
        int user_set_interval_nano;
        int columnNumber;
        
        ofxFloatSlider volumeSlider;
        ofxFloatSlider tempoSlider;
        ofxToggle playPause;
        ofxButton reset;
        ofxPanel gui;

        ofSoundPlayer kick;
        ofSoundPlayer snare;
        ofSoundPlayer rim;
        ofSoundPlayer hatClosed;
        ofSoundPlayer hatOpen;
        ofSoundPlayer tamb;
        ofSoundPlayer ride;
        ofSoundPlayer crash;
    
        ofSoundPlayer* soundArray[8];   

        
		
};



