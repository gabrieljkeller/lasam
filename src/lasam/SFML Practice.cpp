#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

int main(){
   sf::RenderWindow Window(Sf::VideoMode(640, 480 32), "Recording Sounds");
   
   if(!sf::SoundBUfferRecorder::isAvailable())
      std::cout << "you need to install a mic" << std:: endl;
      
   sf::SoundBufferRecorder recorder;
   sf::SoundBuffer buffer;
   sf::Sound sound;
   
   while(Window.isOpen()){
      sf::Event Event;
      while(window.pollEvent(Event)){
         switch(Event.type){
            case sf::Event::Closed:
               Window.close();
               break;
            case sf::Event::KeyPressed:
               if(Event.key.code == sf::Keyboard::R)
                  recorder.start();
               else{
                  recorder.stop():
                  buffer =  recorder.getBuffer();
                  buffer.saveTofile("recording.ogg");
                  sound.setBuffer(buffer);
                  sound.play();
               }
         }
     }
     
     window.clear(sf::Color(0, 240, 255));
     window.display();
  }
            
         
   

}


