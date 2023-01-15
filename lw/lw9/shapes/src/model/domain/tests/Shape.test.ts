import {Shape} from "../Shape";
import {ShapeType} from "../ShapeType";
import {getDefaultShapeData} from "../../../common/defaultValues";

describe('Testing the shape', () => {
    const defaultFrame = getDefaultShapeData().frame

    it('Creating a rectangle', () => {
        const shape = new Shape(ShapeType.RECTANGLE)

        expect(shape.getUuid()).toBeTruthy()
        expect(shape.getType()).toBe(ShapeType.RECTANGLE)
        expect(shape.getFrame()).toEqual(defaultFrame)
    })

    it('Creating a triangle', () => {
        const shape = new Shape(ShapeType.TRIANGLE)

        expect(shape.getUuid()).toBeTruthy()
        expect(shape.getType()).toBe(ShapeType.TRIANGLE)
        expect(shape.getFrame()).toEqual(defaultFrame)
    })

    it('Creating an ellipse', () => {
        const shape = new Shape(ShapeType.ELLIPSE)

        expect(shape.getUuid()).toBeTruthy()
        expect(shape.getType()).toBe(ShapeType.ELLIPSE)
        expect(shape.getFrame()).toEqual(defaultFrame)
    })

    it('Changing the shape frame', () => {
        const shape = new Shape(ShapeType.RECTANGLE)
        const newFrame = {
            leftTop: {
                x: 150,
                y: 100,
            },
            width: 150,
            height: 200,
        }

        shape.setFrame(newFrame)
        expect(shape.getFrame()).toEqual(newFrame)
    })
})
