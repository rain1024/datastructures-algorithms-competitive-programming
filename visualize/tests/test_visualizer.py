import unittest
from graphics import Circle, Line, Arrow
from graph import Graph
from visualizer import Visualizer, SvgVisualizer
import svgwrite
import os


class TestVisualizer(unittest.TestCase):
    def test_visualize_undirected(self):
        # Create an undirected graph with 3 nodes and 2 edges
        graph = Graph()
        graph.add_edge(1, 2)
        graph.add_edge(2, 3)
        # Ensure the correct GraphicObject instances are returned
        visualizer = Visualizer()
        graphic_objects = visualizer.visualize(graph)
        self.assertEqual(len(graphic_objects), 5)
        self.assertIsInstance(graphic_objects[0], Circle)
        self.assertIsInstance(graphic_objects[1], Circle)
        self.assertIsInstance(graphic_objects[4], Line)
    
    def test_visualize_directed(self):
        # Create a directed graph with 3 nodes and 2 edges
        graph = Graph(directed=True)
        graph.add_edge(1, 2)
        graph.add_edge(2, 3)
        # Ensure the correct GraphicObject instances are returned
        visualizer = SvgVisualizer()
        graphic_objects = visualizer.visualize(graph)
        self.assertEqual(len(graphic_objects), 5)
        self.assertIsInstance(graphic_objects[0], Circle)
        self.assertIsInstance(graphic_objects[1], Circle)
        self.assertIsInstance(graphic_objects[4], Arrow)


class TestSvgVisualizer(unittest.TestCase):
    def setUp(self):
        self.skip_tear_down = False
        self.directed_filepath = "directed_graph.svg"
        self.undirected_filepath = "undirected_graph.svg"
        undirected_graph = Graph()
        undirected_graph.add_edge(1, 2)
        undirected_graph.add_edge(2, 3)
        undirected_graph.add_edge(3, 4)
        self.undirected_graph = undirected_graph

        directed_graph = Graph(directed=True)
        directed_graph.add_edge(1, 2)
        directed_graph.add_edge(2, 3)
        directed_graph.add_edge(3, 4)
        self.directed_graph = directed_graph

    

    def tearDown(self):
        if self.skip_tear_down:
            return
        # Delete the files created by the test
        for filepath in [self.directed_filepath, self.undirected_filepath]:
            try:
                os.remove(filepath)
            except FileNotFoundError:
                pass

    def test_draw(self):
        # Create an instance of SvgVisualizer
        visualizer = SvgVisualizer()

        # Call the draw method
        objects = visualizer.visualize(self.directed_graph)
        drawing = visualizer.draw(objects)

        # Check that the returned value is an svgwrite.Drawing object
        self.assertIsInstance(drawing, svgwrite.Drawing)

    def test_write(self):
        # Create a Graph object with a few nodes and edges
        

        # Create an instance of SvgVisualizer
        visualizer = SvgVisualizer()

        graphic_objects = visualizer.visualize(self.directed_graph)
        visualizer.write(self.directed_filepath, graphic_objects)
        self.assertTrue(os.path.exists(self.directed_filepath))

        graphic_objects = visualizer.visualize(self.undirected_graph)
        visualizer.write(self.undirected_filepath, graphic_objects)
        self.assertTrue(os.path.exists(self.undirected_filepath))

        self.skip_tear_down = True


if __name__ == "__main__":
    unittest.main()
