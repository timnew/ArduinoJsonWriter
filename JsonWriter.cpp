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
        if(!separatorAlreadyCalled){
          ifSeparator();
          separatorAlreadyCalled = true;
        }
	stream->print("{");
        firstElement = true;
	return *this;
}

JsonWriter& JsonWriter::beginObject(String name){
      if(!separatorAlreadyCalled){
          ifSeparator();
          separatorAlreadyCalled = true;
        }
        memberName(name);
	stream->print("{");
        firstElement = true;
	return *this;
}

JsonWriter& JsonWriter::property(String name, char* value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        string(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, String value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        string(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, int value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, unsigned int value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, long value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, unsigned long value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, short value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, unsigned short value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, byte value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, float value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, double value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        number(value);
        separatorAlreadyCalled = false;
	return *this;
}

JsonWriter& JsonWriter::property(String name, bool value){
        ifSeparator();
        separatorAlreadyCalled = true;
        memberName(name);
        boolean(value);
        separatorAlreadyCalled = false;
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
        if(!separatorAlreadyCalled){
          ifSeparator();
        }
        firstElement = true;
	stream->print("[");
	return *this;
}

JsonWriter& JsonWriter::beginArray(String name){

        if(!separatorAlreadyCalled){
          ifSeparator();
          separatorAlreadyCalled = true;
        }
        firstElement = true;
        memberName(name);
        separatorAlreadyCalled = false;
	stream->print("[");
	return *this;
}


JsonWriter& JsonWriter::endArray(){
	stream->print("]");
	return *this;
}

JsonWriter& JsonWriter::string(char* text){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print("\"");
	stream->print(text);
	stream->print("\"");
	return *this;
}
JsonWriter& JsonWriter::string(String text){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print("\"");
	stream->print(text);
	stream->print("\"");
	return *this;
}

JsonWriter& JsonWriter::number(int number){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(unsigned int number){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(long number){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(unsigned long number){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(short number){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(unsigned short number){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(number, DEC);
	return *this;
}
JsonWriter& JsonWriter::number(byte number){
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(number, DEC);
	return *this;
}

JsonWriter& JsonWriter::number(float number){
        if(!separatorAlreadyCalled)
          ifSeparator();
        stream->print(number);
        return *this;
}
JsonWriter& JsonWriter::number(double number){
        if(!separatorAlreadyCalled)
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
        if(!separatorAlreadyCalled)
          ifSeparator();
	stream->print(value ? "true" : "false");
	return *this;
}
