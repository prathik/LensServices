CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 

OBJS =		LensServices.o CurlWrapper.o Lens.o

LIBS =		-lcurl

TARGET =	LensServices

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

CurlWrapper.o:
	$(CXX) -o CurlWrapper.o -c CurlWrapper.cpp $(LIBS)
	
Lens.o:
	$(CXX) -o Lens.o -c Lens.cpp $(LIBS)

clean:
	rm -f $(OBJS) $(TARGET)
