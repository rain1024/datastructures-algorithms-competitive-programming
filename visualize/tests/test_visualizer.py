import unittest
from graphics import Circle, Rectangle, Line
from graph import Graph
from graphics import GraphicObject
from visualizer import Visualizer, SvgVisualizer
import svgwrite
import os


class TestVisualizer(unittest.TestCase):
    def test_visualize(self):
        # Create a graph with two nodes and one edge
        graph = Graph()
        graph.add_edge(1, 2)

        # Create an instance of Visualizer
        visualizer = Visualizer()

        # Call the visualize method and store the result in a variable
        graphic_objects = visualizer.visualize(graph)

        self.assertEqual(len(graphic_objects), 4)

        # Check that the first element is a Circle
        self.assertIsInstance(graphic_objects[0], Circle)

        # Check that the second element is a Line
        self.assertIsInstance(graphic_objects[3], Line)


class TestSvgVisualizer(unittest.TestCase):
    def setUp(self):
        self.skip_tear_down = False
        self.filepath = ""

    def tearDown(self):
        if self.skip_tear_down:
            return
        # Delete the file created by the test
        try:
            os.remove(self.filepath)
        except FileNotFoundError:
            pass

    def test_draw(self):
        # Create a Graph object with a few nodes and edges
        graph = Graph()
        graph.add_edge(1, 2)
        graph.add_edge(2, 3)
        graph.add_edge(3, 4)

        # Create an instance of SvgVisualizer
        visualizer = SvgVisualizer()

        # Call the draw method
        objects = visualizer.visualize(graph)
        drawing = visualizer.draw(objects)

        # Check that the returned value is an svgwrite.Drawing object
        self.assertIsInstance(drawing, svgwrite.Drawing)

    def test_write(self):
        # Create a Graph object with a few nodes and edges
        self.filepath = "test.svg"
        graph = Graph()
        graph.add_edge(1, 2)
        graph.add_edge(2, 3)
        graph.add_edge(3, 4)

        # Create an instance of SvgVisualizer
        visualizer = SvgVisualizer()
        graphic_objects = visualizer.visualize(graph)

        # Call the write method
        visualizer.write(self.filepath, graphic_objects)

        # Check that the file was created
        self.assertTrue(os.path.exists(self.filepath))

        self.skip_tear_down = True


if __name__ == "__main__":
    unittest.main()
