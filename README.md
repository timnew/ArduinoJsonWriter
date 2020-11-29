PrettyJsonWriter
=================
An improved fork of ArduinoJsonWriter by Robert van den Breemen (29 november 2020)

Json Writer is a light weight library that make it easier to generate json document on Arduino. 

The 2020 edition improved on the orginal by fixing and improving in the following ways: 
- fixing the class so the object can be used in loops (beginDocument/endDocument)
- adding pretty print function (even more readable Json for Humans) 

The library works pretty similar to the SAX for XML, it treats JSON as a stream of nodes. With the API, you can compose a JSON document by emitting each node to the stream directly not claiming more memory than absolutly needed to generate the JSON. 

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
	writer.boolean(true);					 // true	
	writer.boolean(false);					 // false

### Emit Array
	writer
	  .beginDocument()
	  .beginArray()
	  .string("alpha")
	  .string("beta")
	  .null()
	  .string("gamma")
	  .number(123)
	  .endArray()
	  .endDocument(); 					        
	  // ["aplha","beta",null,"gamma",123]

### Emit Object
	writer
	.beginDocument()
	  .beginObject()
            .property("Real name","Thomas A. Anderson")
            .property("Hacker name","Neo")
            .property("Entity","The One")
            .property("Height",185)
            .property("isCreatedByArchitect",true)
	  .endObject()
	.endDocument();  
	  
	  // {"Real name":"Thomas A. Anderson","Hacker name":"Neo","Entity":"The One","Height":185,"isCreatedByArchitect":true}
	  
### Array of objects
	writer
	.beginDocument()
	  .beginArray()
            .beginObject()
                .property("name", "alpha")
            .endObject()
            .beginObject()
                .property("name", "beta")
                .property("anotherProperty", 12.67)
            .endObject()
            .beginObject()
                .property("name", "gamma")
            .endObject()
	  .endArray()
	.endDocument(); 					        
	  // [{"name":"alpha"},{"name":"beta","anotherProperty":12.67},{"name":"gamma"}]
	  
### Nested Objects and arrays
	writer
	.beginDocument()
	  .beginObject()
	    .property("id", 7)
	    .beginObject("name")
                .property("firstName","James")
                .property("lastName","Bond")
            .endObject()
            .beginArray("languages")
                .string("English")
                .string("Russian")
            .endArray()
            .beginArray("gadgets")
                .beginObject()
                    .property("name", "Laser watch")
                    .property("returned", false)
                .endObject()
                .beginObject()
                    .property("name", "Walther PP")
                    .property("returned", false)
                    .beginArray("calibers")
                        .number(32)
                        .number(380)
                        .number(22)
                    .endArray()
                .endObject()
            .endArray()
	  .endObject()
  	.endDocument();   
	  
	  // {"id":7,"name":{"firstName":"James","lastName":"Bond"},"languages":["English","Russian"],"gadgets":[{"name":"Laser watch","returned":0},{"name":"Walther PP","returned":0,"calibers":[32,380,22]}]}
	  
