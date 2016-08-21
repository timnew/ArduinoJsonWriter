#include "JsonWriter.h"

JsonWriter::JsonWriter(Stream* stream)
	:stream(stream){
}

// This function checks if a separator should be printed
void JsonWriter::ifSeparator(){
        if(firstElement){
          firstElement = false;
        } else {
          separator();
        }
}

JsonWriter& JsonWriter::beginObject(){
        ifSeparator();
	stream->print("{");
        firstElement = true;
	return *this;
}

JsonWriter& JsonWriter::beginObject(String name){
        ifSeparator();
        memberName(name);
	stream->print("{");
        firstElement = true;
	return *this;
}

JsonWriter& JsonWriter::property(String name, char* value){
        ifSeparator();
        memberName(name);
        string(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, String value){
        ifSeparator();
        memberName(name);
        string(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, int value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, unsigned int value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, long value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, unsigned long value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, short value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, unsigned short value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, byte value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, float value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::property(String name, double value){
        ifSeparator();
        memberName(name);
        number(value);
	return *this;
}

JsonWriter& JsonWriter::memberName(String name){
	string(name);	
	stream->print(':');
	return *this;
}
JsonWriter& JsonWriter::memberName(char* name){
	string(name);
	stream->print(':');
	return *this;
}

JsonWriter& JsonWriter::separator(){
	stream->print(",");
	return *this;

}
JsonWriter& JsonWriter::endObject(){
	stream->print("}");
	return *this;
}

JsonWriter& JsonWriter::beginArray(){
        ifSeparator();
        firstElement = true;
	stream->print("[");
	return *this;
}

JsonWriter& JsonWriter::beginArray(String name){

        ifSeparator();
        firstElement = true;
        memberName(name);
	stream->print("[");
	return *this;
}


JsonWriter& JsonWriter::endArray(){
	stream->print("]");
	return *this;
}

JsonWriter& JsonWriter::string(char* text){
        ifSeparator();
	stream->print("\"");
	stream->print(text);
	stream->print("\"");
	return *this;
}
JsonWriter& JsonWriter::string(String text){
        ifSeparator();
	stream->print("\"");
	stream->print(text);
	stream->print("\"");
	return *this;
}
	
JsonWriter& JsonWriter::number(int number){
        ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(unsigned int number){
        ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(long number){
        ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(unsigned long number){
        ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(short number){
        ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(unsigned short number){
        ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(byte number){
        ifSeparator();
	stream->print(number, DEC);
	return *this;
}

JsonWriter& JsonWriter::number(float number){
        ifSeparator();
 stream->print(number);
 return *this;
}
JsonWriter& JsonWriter::number(double number){
        ifSeparator();
 stream->print(number);
 return *this;
}

JsonWriter& JsonWriter::null(){
        ifSeparator();
	stream->print("null");
	return *this;
}

JsonWriter& JsonWriter::boolean(bool value){
        ifSeparator();
	stream->print(value ? "true" : "false");
	return *this;
}
