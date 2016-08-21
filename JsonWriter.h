#ifndef __JSON_WRITER_H__
#define __JSON_WRITER_H__

#include "Arduino.h"

class JsonWriter {
private:
	Stream* stream;
        bool firstElement = true;
        void ifSeparator();

public:
	JsonWriter(Stream* stream);

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