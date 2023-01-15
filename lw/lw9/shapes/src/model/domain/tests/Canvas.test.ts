import {Canvas} from "../Canvas";
import {Shape} from "../Shape";
import {ShapeType} from "../ShapeType";

describe('Testing canvas', () => {

    it('Creating a canvas', () => {
        const canvas = new Canvas()

        expect(canvas.getShapesCount()).toBe(0)
        expect(canvas.getShapes()).toEqual([])
    })

    it('Inserting a shape', () => {
        const canvas = new Canvas()
        const shape = new Shape(ShapeType.RECTANGLE)

        canvas.insertShape(shape, 0)

        expect(canvas.getShapesCount()).toBe(1)
        expect(canvas.getShapes()).toEqual([shape])
    })

    it('Inserting a shape into a larger index', () => {
        const canvas = new Canvas()
        const shape = new Shape(ShapeType.RECTANGLE)

        canvas.insertShape(shape, 1)

        expect(canvas.getShapesCount()).toBe(1)
        expect(canvas.getShapes()).toEqual([shape])
    })

    it('Deleting a shape', () => {
        const canvas = new Canvas()
        const shape = new Shape(ShapeType.RECTANGLE)
        canvas.insertShape(shape, 0)

        canvas.deleteShape(shape.getUuid())

        expect(canvas.getShapesCount()).toBe(0)
        expect(canvas.getShapes()).toEqual([])
    })

    it('Replacing a shape', () => {
        const canvas = new Canvas()
        const shape = new Shape(ShapeType.RECTANGLE)
        canvas.insertShape(shape, 0)
        const newFrame = {
            leftTop: {
                x: 150,
                y: 100,
            },
            width: 150,
            height: 200,
        }
        shape.setFrame(newFrame)

        canvas.replaceShape(shape)

        expect(canvas.getShapesCount()).toBe(1)
        expect(canvas.getShapes()).toEqual([shape])
    })

    it('Replacing a non-existent shape', () => {
        const canvas = new Canvas()
        const rectangle = new Shape(ShapeType.RECTANGLE)
        const ellipse = new Shape(ShapeType.ELLIPSE)
        canvas.insertShape(rectangle, 0)

        canvas.replaceShape(ellipse)

        expect(canvas.getShapesCount()).toBe(1)
        expect(canvas.getShapes()).toEqual([rectangle])
    })

    it('Inserting multiple shapes', () => {
        const canvas = new Canvas()
        const rectangle = new Shape(ShapeType.RECTANGLE)
        const triangle = new Shape(ShapeType.TRIANGLE)
        const ellipse = new Shape(ShapeType.ELLIPSE)

        canvas.insertShape(rectangle, 0)
        canvas.insertShape(triangle, 0)
        canvas.insertShape(ellipse, 1)

        expect(canvas.getShapesCount()).toBe(3)
        expect(canvas.getShapes()).toEqual([triangle, ellipse, rectangle])
    })
})
