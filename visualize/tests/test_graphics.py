import unittest

from graphics import Circle, Rectangle, Line, Arrow, Text


class TestCircle(unittest.TestCase):
    def test_init(self):
        circle = Circle((0, 0), 3, color="red", filled=True)
        self.assertEqual(circle.type, "circle")
        self.assertEqual(circle.center, (0, 0))
        self.assertEqual(circle.radius, 3)
        self.assertEqual(circle.kwargs, {"color": "red", "filled": True})

    def test_center_as_float(self):
        circle = Circle((0.5, 0.5), 3, color="red", filled=True)
        self.assertEqual(circle.center, (0.5, 0.5))

    def test_negative_radius(self):
        circle = Circle((0, 0), -3, color="red", filled=True)
        self.assertEqual(circle.radius, -3)

    def test_color_as_none(self):
        circle = Circle((0, 0), 3, color=None, filled=True)
        self.assertEqual(circle.kwargs, {"color": None, "filled": True})

    def test_additional_kwargs(self):
        circle = Circle((0, 0), 3, color="red", filled=True, linewidth=2)
        self.assertEqual(
            circle.kwargs, {"color": "red", "filled": True, "linewidth": 2}
        )


class TestRectangle(unittest.TestCase):
    def test_init(self):
        rectangle = Rectangle((0, 0), (3, 4), color="blue", filled=False)
        self.assertEqual(rectangle.type, "rectangle")
        self.assertEqual(rectangle.top_left, (0, 0))
        self.assertEqual(rectangle.bottom_right, (3, 4))
        self.assertEqual(rectangle.kwargs, {"color": "blue", "filled": False})

    def test_coordinates_as_float(self):
        rectangle = Rectangle((0.5, 0.5), (3.5, 4.5), color="blue", filled=False)
        self.assertEqual(rectangle.top_left, (0.5, 0.5))
        self.assertEqual(rectangle.bottom_right, (3.5, 4.5))

    def test_negative_coordinates(self):
        rectangle = Rectangle((-1, -1), (-2, -2), color="blue", filled=False)
        self.assertEqual(rectangle.top_left, (-1, -1))
        self.assertEqual(rectangle.bottom_right, (-2, -2))

    def test_color_as_none(self):
        rectangle = Rectangle((0, 0), (3, 4), color=None, filled=False)
        self.assertEqual(rectangle.kwargs, {"color": None, "filled": False})

    def test_additional_kwargs(self):
        rectangle = Rectangle((0, 0), (3, 4), color="blue", filled=False, linewidth=2)
        self.assertEqual(
            rectangle.kwargs, {"color": "blue", "filled": False, "linewidth": 2}
        )


class TestLine(unittest.TestCase):
    def test_init(self):
        line = Line((0, 0), (3, 4), color="green", dashed=True)
        self.assertEqual(line.type, "line")
        self.assertEqual(line.start, (0, 0))
        self.assertEqual(line.end, (3, 4))
        self.assertEqual(line.kwargs, {"color": "green", "dashed": True})

    def test_coordinates_as_float(self):
        line = Line((0.5, 0.5), (3.5, 4.5), color="green", dashed=True)
        self.assertEqual(line.start, (0.5, 0.5))
        self.assertEqual(line.end, (3.5, 4.5))

    def test_negative_coordinates(self):
        line = Line((-1, -1), (-2, -2), color="green", dashed=True)
        self.assertEqual(line.start, (-1, -1))
        self.assertEqual(line.end, (-2, -2))

    def test_color_as_none(self):
        line = Line((0, 0), (3, 4), color=None, dashed=True)
        self.assertEqual(line.kwargs, {"color": None, "dashed": True})

    def test_additional_kwargs(self):
        line = Line((0, 0), (3, 4), color="green", dashed=True, linewidth=2)
        self.assertEqual(
            line.kwargs, {"color": "green", "dashed": True, "linewidth": 2}
        )


class TestArrowObject(unittest.TestCase):
    def test_arrow_object(self):
        # Create an ArrowObject instance
        start = (0, 0)
        end = (100, 100)
        arrow = Arrow(start, end, color="red", head_width=10, head_length=20)

        # Test that the ArrowObject was created with the correct attributes
        self.assertEqual(arrow.type, "arrow")
        self.assertEqual(arrow.start, start)
        self.assertEqual(arrow.end, end)
        self.assertEqual(
            arrow.kwargs, {"color": "red", "head_width": 10, "head_length": 20}
        )


class TestTextObject(unittest.TestCase):
    def test_text_object(self):
        text = Text(text="Hello", position=(100, 100))
        self.assertEqual(text.type, "text")
        self.assertEqual(text.position, (100, 100))
        self.assertEqual(text.content, "Hello")


if __name__ == "__main__":
    unittest.main()
