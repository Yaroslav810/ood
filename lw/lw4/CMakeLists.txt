set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(
        lw4
        main.cpp
        lib/Canvas/ICanvas.h
        lib/Canvas/CCanvas.h
        lib/Canvas/CCanvas.cpp
        lib/Color/Color.h
        lib/Designer/IDesigner.h
        lib/Designer/CDesigner.h
        lib/Designer/CDesigner.cpp
        lib/Painter/CPainter.h
        lib/Painter/CPainter.cpp
        lib/PictureDraft/CPictureDraft.h
        lib/PictureDraft/CPictureDraft.cpp
        lib/Shape/CShape.h
        lib/Shape/CShape.cpp
        lib/ShapeFactory/IShapeFactory.h
        lib/Point/CPoint.h
        lib/Point/CPoint.cpp
        lib/Shape/Rectangle/CRectangle.h
        lib/Shape/Rectangle/CRectangle.cpp
        lib/Shape/Triangle/CTriangle.h
        lib/Shape/Triangle/CTriangle.cpp
        lib/Shape/Ellipse/CEllipse.h
        lib/Shape/Ellipse/CEllipse.cpp
        lib/Shape/RegularPolygon/CRegularPolygon.h
        lib/Shape/RegularPolygon/CRegularPolygon.cpp
        lib/ShapeFactory/IShapeFactory.h
        lib/ShapeFactory/CShapeFactory.h
        lib/ShapeFactory/CShapeFactory.cpp
)

add_executable(
        lw4_test
        tests/lw4_test.cpp
        lib/Canvas/ICanvas.h
        lib/Canvas/CCanvas.h
        lib/Canvas/CCanvas.cpp
        lib/Color/Color.h
        lib/Designer/IDesigner.h
        lib/Designer/CDesigner.h
        lib/Designer/CDesigner.cpp
        lib/Painter/CPainter.h
        lib/Painter/CPainter.cpp
        lib/PictureDraft/CPictureDraft.h
        lib/PictureDraft/CPictureDraft.cpp
        lib/Shape/CShape.h
        lib/Shape/CShape.cpp
        lib/ShapeFactory/IShapeFactory.h
        lib/Point/CPoint.h
        lib/Point/CPoint.cpp
        lib/Shape/Rectangle/CRectangle.h
        lib/Shape/Rectangle/CRectangle.cpp
        lib/Shape/Triangle/CTriangle.h
        lib/Shape/Triangle/CTriangle.cpp
        lib/Shape/Ellipse/CEllipse.h
        lib/Shape/Ellipse/CEllipse.cpp
        lib/Shape/RegularPolygon/CRegularPolygon.h
        lib/Shape/RegularPolygon/CRegularPolygon.cpp
        lib/ShapeFactory/IShapeFactory.h
        lib/ShapeFactory/CShapeFactory.h
        lib/ShapeFactory/CShapeFactory.cpp
)

set(SFML_DIR "./../../sfml/SFML-2.5.1/lib/cmake/SFML")

target_link_libraries(lw4 sfml-graphics)
target_link_libraries(lw4_test sfml-graphics)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED window graphics system)
