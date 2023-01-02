import unittest
from typing import List

from graphics import Circle, Rectangle, Line
from graph import Graph
from graphics import GraphicObject
from visualizer import Visualizer

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


if __name__ == '__main__':
    unittest.main()
