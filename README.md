ArduinoJsonWriter
=================

Json Writer is a light weight library that make it easier to generate json document on Arduino.

The library works pretty similar to the SAX for XML, it treats JSON as a stream of nodes. With the API, you can compose a JSON document by emitting each node.


Initialize JsonWriter
---------------------
JsonWriter wraps a Stream instance, so it could be used to generate data for all kind of Stream based IO or starages, including: `Serial`, `Wire(I2C)`, `Ethernet TCP socket`, `SD`


	JsonWriter serialJsonWriter(Serial);

	JsonWriter wireJsonWriter(Wire);

	JsonWriter ethernetJsonWriter1(ethernetClient);

	JsonWriter ethernetJsonWriter2(ethernetServer);


Usage
------

### Emit Primitives

	writer.string("Json String");           // "Json String"
	writer.string("0x" + String(255,HEX));  // "0xFF"

	writer.number(23);						 // 23

	writer.null();							 // null
	
	writer.boolean(true);					 // true	writer.boolean(false);					 // false

### Emit Array
	writer
	  .beginArray()
	  .string("alpha")
	  .separator()
	  .string("beta")
	  .separator()
	  .string("gamma")
	  .endArray(); 					        // ["aplha","beta","gamma"]

### Emit Object
	writer
	  .beginObject()

	  .memberName("	Real name")
	  .string("Thomas A. Anderson")
	  .separator()

	  .memberName("Hacker name"))
	  .string("Neo")
	  .separator()

	  .memberName("Entity")
	  .string("The One")
	  .separator()

	  .memberName("Height")
	  .number(185)
	  .seperator()
	  
	  .memberName("isCreatedByArchitect")
	  .boolean(true)
	  .seperator()

	  .endObject(); 
	  
	  // {"Real name":"Thomas A. Anderson","Hacker name":"Neo","Entity":"The One","Height":185,"isCreatedByArchitect":true}
