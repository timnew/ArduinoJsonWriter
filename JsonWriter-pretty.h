#ifndef __JSON_WRITER_H__
#define __JSON_WRITER_H__

#include "Arduino.h"

class JsonWriter {
private:
	Stream* stream;
        /* The first element should not print a separator before them */
        bool firstElement = true;
        /* When the separator is already written, it should never be printed again until next element.
           This is caused because the method "property" writes a separator and the base type too. In this
           case only the method "property" should write it. The base type tries to write a separator to allow
           arrays of base types (array of integers for example)*/
        bool separatorAlreadyCalled = false;
        void ifSeparator();
		void printIndent();
		bool prettyPrint = true;
		int countIndent = 0;

public:
	JsonWriter(Stream* stream);

	JsonWriter& beginDocument();
	JsonWriter& beginDocument(bool value);
	JsonWriter& endDocument();

	JsonWriter& beginObject();
	JsonWriter& beginObject(String name);
	JsonWriter& memberName(char* name);
	JsonWriter& memberName(String name);
	JsonWriter& separator();
	JsonWriter& endObject();

	JsonWriter& beginArray();
  	JsonWriter& beginArray(String name);
	JsonWriter& endArray();

	JsonWriter& property(String name, char* value);
  	JsonWriter& property(String name, String value);

	JsonWriter& property(String name, int value);
	JsonWriter& property(String name, unsigned int value);
	JsonWriter& property(String name, long int value);
	JsonWriter& property(String name, unsigned long int value);
	JsonWriter& property(String name, short value);
	JsonWriter& property(String name, unsigned short value);
	JsonWriter& property(String name, byte value);
	JsonWriter& property(String name, float value);
	JsonWriter& property(String name, double value);
	JsonWriter& property(String name, bool value);

	JsonWriter& string(char* text);
	JsonWriter& string(String text);

	JsonWriter& number(int number);
	JsonWriter& number(unsigned int number);
	JsonWriter& number(long number);
	JsonWriter& number(unsigned long number);
	JsonWriter& number(short number);
	JsonWriter& number(unsigned short number);
	JsonWriter& number(byte number);
	JsonWriter& number(float number);
	JsonWriter& number(double number);

	JsonWriter& null();

	JsonWriter& boolean(bool value);

	int operator[](char *);
};

#endif __JSON_WRITER_H__
