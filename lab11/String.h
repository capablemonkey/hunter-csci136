#ifndef STRING_H
#define STRING_H

class String {
	private:
		char chars[80];
		int length;

	public:
		String();
		String(char input[]);

		void copy(char input[]);
		const char* str() const;
		void concat(char input[]);
		int size() const;
};

#endif