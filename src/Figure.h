
class Figure {
public:
  Figure(const int width, const int height) : width(width), height(height){
      buffer = new int[width * height];
    clearBuffer();
}
  ~Figure();

  void draw() const {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        std::cout << buffer[line * width + col] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }


protected:
  bool setPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    buffer[line * width + col] = 1;
    return true;
  }

  bool clearPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    buffer[line * width + col] = 0;
    return true;
  }

  void clearBuffer() {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        buffer[line * width + col] = 0;
      }
    }
  }

  bool drawVertLine(const int col) {
    if (col < 0 || col >= width) {
      return false;
    }

    for (int counter = 0; counter < height; counter++) {
      if (!setPoint(col, counter)) {
        std::cout << "Unable to set point : [" << col << ", " << counter << "]"
                  << std::endl;
      }
    }
    return true;
  }

  bool drawHorLine(const int line) {
    if (line < 0 || line >= height) {
      return false;
    }

    for (int counter = 0; counter < width; counter++) {
      if (!setPoint(counter, line)) {
        std::cout << "Unable to set point : [" << counter << ", " << line << "]"
                  << std::endl;
      }
    }
    return true;
  }

protected:
  int *buffer;

  int width;
  int height;
};