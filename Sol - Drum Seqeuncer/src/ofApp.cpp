#include "ofApp.h"

static bool grid[16][8];

//--------------------------------------------------------------
void ofApp::setup(){

    tempoSlider.addListener(this, &ofApp::tempoChanged);
    ofBackground(255,255,255);
    
    gui.setup();
    gui.add(volumeSlider.setup("Volume", 0.5, 0.1, 1.0));
    gui.add(tempoSlider.setup("Tempo", 120.0, 10.0, 200.0));
    gui.add(playPause.setup("Play/Pause", true));
    gui.add(reset.setup("Reset"));
    
    padding_x = 120;
    padding_y = 120;
    cell_width = 50;
    cell_height = 20;
    cell_spacing = 2;
    cell_colour_off = 0xFFFFFF; //white
    cell_colour_on = 0x0000FF; //blue
    background_colour = 0x808080; //grey
    columnNumber = 0;
    
    kick.load("Kick_707.wav");
    soundArray[7] = &kick;
    
    snare.load("Snare_707.wav");
    soundArray[6] = &snare;
    
    rim.load("Rim_707.wav");
    soundArray[5] = &rim;
    
    hatClosed.load("Hatclosed_707.wav");
    soundArray[4] = &hatClosed;
    
    hatOpen.load("HatOpen_707.wav");
    soundArray[3] = &hatOpen;
    
    tamb.load("Tamb_707.wav");
    soundArray[2] = &tamb;
    
    ride.load("Ride_707.wav");
    soundArray[1] = &ride;
    
    crash.load("Crash_707.wav");
    soundArray[0] = &crash;
    
    scheduler = new Scheduler(100000000, this);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    if (reset == 1) {
        memset(grid, 0, sizeof(grid));
        
    }
}

void ofApp::tempoChanged(float &tempoSlider){
    tempo_input = tempoSlider;
    ofLog() << tempo_input;
    int oldTempo = 120.0;
    int newTempo = tempo_input;

    user_set_interval_nano = ((60.0 / tempo_input) * 1000000000.0) / 4;
    ofLog() << user_set_interval_nano;
    
    if (oldTempo != newTempo) {
        scheduler->setTimer(user_set_interval_nano);
        oldTempo = newTempo;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    int background_width = 16 * cell_width + 17 * cell_spacing;
    int background_height = 8 * cell_height + 9 * cell_spacing;
    
    //Draw Background rectangle
    ofSetHexColor(background_colour);
    ofDrawRectangle(padding_x,padding_y, background_width, background_height);
        
    //Draw inner cells
    for (int y = 0; y < 8; y++ ) {
        for (int x = 0; x < 16; x ++) {
            int y_pos = padding_y + cell_spacing + y * (cell_height + cell_spacing);
            int x_pos = padding_x + cell_spacing + x * (cell_width + cell_spacing);
            
            if (x==columnNumber) {
                ofSetHexColor(0xFF0000);
            }
            
            else {
                if (grid[x][y] == 1) {
                    ofSetHexColor(cell_colour_on);
                } else if (grid[x][y] == 0) {
                    ofSetHexColor(cell_colour_off);
                }
            }
            ofDrawRectangle(x_pos, y_pos, cell_width, cell_height);
        }
    }
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int a = 0; a < 8; a++ ) {
        for (int b = 0; b < 16; b ++) {
            int y_corner_L = padding_y + cell_spacing + a * (cell_height + cell_spacing);
            int x_corner_L = padding_x + cell_spacing + b * (cell_width + cell_spacing);
            
            if ((x > x_corner_L && x < x_corner_L + cell_width) && (y > y_corner_L && y < y_corner_L + cell_height)) {
                ofLog() << "cell!" << a << b;
                grid[b][a] = !grid[b][a];
                ofLog() << grid[b][a];
                
            }
            
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


void ofApp::tick(){
    if (playPause == 1) {
        columnNumber ++;
        
        if (columnNumber == 16) {
            columnNumber = 0;
        }
        
        for (int row = 0; row < 8 ; row++){
            if (grid[columnNumber][row]) {
                soundArray[row]->setVolume(volumeSlider);
                soundArray[row]->play();
                
            }
        }
    
    }
    
}

