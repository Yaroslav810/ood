set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(
        lw7
        main.cpp
        lib/Shape/IShape.h
        lib/Canvas/ICanvas.h
        lib/Canvas/CCanvas/CCanvas.h
        lib/Canvas/CCanvas/CCanvas.cpp
        lib/Common/CommonTypes.h
        lib/Common/IDrawable.h
        lib/GroupShape/IGroupShape.h
        lib/GroupShape/IShapes.h
        lib/GroupShape/CGroupShape/CGroupShape.h
        lib/GroupShape/CGroupShape/CGroupShape.cpp
        lib/GroupShape/Style/IGroupStyle.h
        lib/Shape/CShape/CShape.h
        lib/Shape/CShape/CShape.cpp
        lib/Shape/CEllipse/CEllipse.h
        lib/Shape/CEllipse/CEllipse.cpp
        lib/Shape/CRectangle/CRectangle.h
        lib/Shape/CRectangle/CRectangle.cpp
        lib/Shape/CTriangle/CTriangle.h
        lib/Shape/CTriangle/CTriangle.cpp
        lib/Common/IFillStyle.h
        lib/Common/ILineStyle.h
        lib/Shape/Style/CShapeFillStyle/CShapeFillStyle.h
        lib/Shape/Style/CShapeFillStyle/CShapeFillStyle.cpp
        lib/Shape/Style/CShapeOutlineStyle/CShapeOutlineStyle.h
        lib/Shape/Style/CShapeOutlineStyle/CShapeOutlineStyle.cpp
        lib/Slide/ISlide.h
        lib/Slide/CSlide.h
        lib/Slide/CSlide.cpp
)

add_executable(
        lw7_test
        tests/lw7_test.cpp
        lib/Canvas/ICanvas.h
        lib/Common/CommonTypes.h
        lib/Common/IDrawable.h
        lib/GroupShape/IGroupShape.h
        lib/GroupShape/IShapes.h
        lib/GroupShape/CGroupShape/CGroupShape.h
        lib/GroupShape/CGroupShape/CGroupShape.cpp
        lib/GroupShape/Style/IGroupStyle.h
        lib/Shape/IShape.h
        lib/Shape/CShape/CShape.h
        lib/Shape/CShape/CShape.cpp
        lib/Shape/CEllipse/CEllipse.h
        lib/Shape/CEllipse/CEllipse.cpp
        lib/Shape/CRectangle/CRectangle.h
        lib/Shape/CRectangle/CRectangle.cpp
        lib/Shape/CTriangle/CTriangle.h
        lib/Shape/CTriangle/CTriangle.cpp
        lib/Common/IFillStyle.h
        lib/Common/ILineStyle.h
        lib/Slide/ISlide.h
        lib/Slide/CSlide.h
        lib/Slide/CSlide.cpp
)

set(SFML_DIR "./../../sfml/SFML-2.5.1/lib/cmake/SFML")

target_link_libraries (lw7 sfml-graphics)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED window graphics system)
