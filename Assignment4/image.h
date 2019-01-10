#ifndef _image_H
#define _image_H

#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class image{
	friend void operator<<(std::ostream & o, image & rhs);
	friend void operator>>(std::istream & i, image & rhs);
	private:
		int width, height;
		std::unique_ptr<unsigned char[]> data;
	public:
		image();
		~image();
		image(std::string filename);
		image & operator=(image & other);
		image(image && other);
		image & operator=(image && other);
		image(image & other);
		image operator+(image & rhs);
		image operator-(image & rhs);
		image operator!(void);
		image operator/(image & rhs);
		image operator*(int f);
		bool operator==(image & rhs);
		
		
		void load(std::string filename);
		void save(std::string filename);

	
		class iterator{
			friend image;
			private:
				unsigned char *ptr;
				// construct only via Image class (begin/end)
				iterator(u_char *p);// : ptr(p) {}
			public://copy construct is public
				iterator(const iterator & rhs);// : ptr(rhs.ptr) {}
				// define overloaded ops: *, ++, --, =
				iterator & operator=(const iterator & rhs);
				void operator++(int);
				void operator--(int);
				unsigned char & operator*(void);
		};
			// define begin()/end() to get iterator to start and
			// "one-past" end.
		iterator begin(void);
		iterator end(void);
};
#endif
