/*
 * DialogBox.h
 *
 *  Created on: 2012-09-08
 *      Author: ajacques
 */

#include "../position.h"
#ifndef DIALOGBOX_H_
#define DIALOGBOX_H_

class DialogBox {
  
  private:
    /* The character/whatever who is talking */
    char* speaker;
  
    /* The message to put in the dialog box */
    char* message;
    
    /* The top left corner's position of the box */
    Position position;
    
    /* The width of the box */
    int width;
    
    /* The height of the box */
    int height;
    
  public:
    /* Constructor */
    DialogBox(char* _speaker, char* _message, Position _position; int _width, int _height) {
      this.speaker = _speaker;
      this.message = _message;
      this.position = _position;
      this.width = _width;
      this.height = _height;
    }
    
    /* Destructor */
    ~DialogBox() {
      delete[] this.speaker;
      delete[] this.message;
    }
  
}

#endif /* DIALOGBOX_H_ */
