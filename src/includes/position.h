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
			this.X = 0;
			this.Y = 0;
		}

		/**
		 * basic position constructor
		 */
		Position(double _X, double _Y)
			this.X = _X;
			this.Y = _Y;
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
			return this.X;
		}

		/**
		 * Y getter
		 * @return double - Y value
		 */
		double getY ( void ) {
			return this.Y;
		}

		/**
		 * X setter
		 * @param double _X - new X value
		 */
		void setX ( double _X ) {
			this.X = _X;
		}

		/**
		 * Y setter
		 * @param double _Y - new Y value
		 */
		void setY ( double _Y ) {
			this.Y = _Y;
		}

		/**
		 * Set position equal to an other one
		 * @param Position _position - New position
		 */
		void setPosition ( Position* _position ) {
			this.X = _position->getX();
			this.Y = _position->getY();
		}

		/**
		 * Add two position (the x's together, the y's together) and output the result
		 * @param Position _position - a position to add
		 */
		Position operator+ ( const Position& _position ) {
			return new Position( this.X + _position.getX(), this.Y + _position.getY() );
		}
};

#endif /* POSITION_H_ */
