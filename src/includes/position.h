/*
 * Position.h
 *
 *  Created on: 2012-09-07
 *      Author: kdorman
 */

#ifndef POSITION_H_
#define POSITION_H_

/**
 * Basic position object
 */
class Position {
	private:
		/**
		 * Position X value
		 */
		double X;
		/**
		 * Position Y value
		 */
		double Y;
	public:
		/**
		 * Zero out constructor
		 */
		Position() {
			X = 0;
			Y = 0;
		}
		/**
		 * basic position constructor
		 */
		Position(double _X, double _Y){
			X = _X;
			Y = _Y;
		}
		/**
		 * empty destructor :(
		 */
		virtual ~Position(){}
		/**
		 * X getter
		 * @return double - X value
		 */
		double getX ( void ) {
			return X;
		}
		/**
		 * Y getter
		 * @return double - Y value
		 */
		double getY ( void ) {
			return Y;
		}
		/**
		 * X setter
		 * @param double _X - new X value
		 */
		void setX ( double _X ) {
			X = _X;
		}
		/**
		 * Y setter
		 * @param double _Y - new Y value
		 */
		void setY ( double _Y ) {
			Y = _Y;
		}
		/**
		 * Set position equal to an other one
		 * @param Position _position - New position
		 */
		void setPosition ( Position* _position ) {
			X = _position->getX();
			Y = _position->getY();
		}
};

#endif /* POSITION_H_ */
