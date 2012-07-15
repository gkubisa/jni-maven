jni-maven
=========

jni-maven is a sample project intended to be used as a template for Java applications using JNI.

How it works
------------

[maven-antrun-plugin][] is added to the *process-classes* phase of the build. It is used to:

- generate the C++ headers using *javah*. They are created in src/main/c++. 
  I did not use *javah* ant target, because it assumes Sun JDK, while I'm using OpenJDK.
- run *make* to build the native code

The Makefile compiles the native code from src/main/c++ into \*.o files which are stored in target/c++. 
Then it runs the linker which produces a single \*.so object stored in *target/classes*.

Because the \*.so file is in *target/classes*, it's included in the final JAR file. This way the
whole project produces a single artifact and can be easily used as a dependency by other Maven projects.

The final bit is the custom module loader *LibraryLoader.loadLibrary*, which extracts the 
native library from the jar into a temporary file and loads it - the standard *System.loadLibrary* cannot do it.

Limitations / possible improvements
-----------------------------------

1. Native code build currently works only on Linux
2. Only C++ is supported as the native language
3. The paths in the Makefile are hard-coded. It would be nice to initialize them from Maven properties.

**Patches welcome!**

Credits
-------

1. <http://docs.codehaus.org/display/MAVENUSER/Projects+With+JNI> - *jni-maven* is a simplified 
   implementation of the concept presented in this article
2. <http://code.google.com/p/jav8/> - *LibraryLoader* class in based on the code from this 
   project (*V8ScriptEngineFactory.java*)

[maven-antrun-plugin]: http://maven.apache.org/plugins/maven-antrun-plugin/
