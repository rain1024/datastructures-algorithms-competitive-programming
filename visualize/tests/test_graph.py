import unittest

from graph import Graph

class TestGraph(unittest.TestCase):
    def test_init(self):
        graph = Graph()
        self.assertEqual(graph.nodes, set())
        self.assertEqual(graph.edges, {})
        self.assertFalse(graph.directed)

        directed_graph = Graph(directed=True)
        self.assertTrue(directed_graph.directed)

    def test_add_edge(self):
        graph = Graph()
        graph.add_edge(1, 2)
        self.assertEqual(graph.nodes, {1, 2})
        self.assertEqual(graph.edges, {1: [2], 2: [1]})

        graph.add_edge(2, 3)
        self.assertEqual(graph.nodes, {1, 2, 3})
        self.assertEqual(graph.edges, {1: [2], 2: [1, 3], 3: [2]})

        directed_graph = Graph(directed=True)
        directed_graph.add_edge(1, 2)
        self.assertEqual(directed_graph.nodes, {1, 2})
        self.assertEqual(directed_graph.edges, {1: [2]})
    
    def test_add_edge_undirected(self):
        graph = Graph(directed=False)
        graph.add_edge(1, 2)
        self.assertEqual(graph.nodes, {1, 2})
        self.assertEqual(graph.edges, {1: [2], 2: [1]})

        graph.add_edge(2, 3)
        self.assertEqual(graph.nodes, {1, 2, 3})
        self.assertEqual(graph.edges, {1: [2], 2: [1, 3], 3: [2]})
    
    def test_add_edge_to_existing_node(self):
        graph = Graph(directed=False)
        graph.add_edge(1, 2)
        graph.add_edge(1, 3)
        graph.add_edge(2, 3)
        self.assertEqual(graph.nodes, {1, 2, 3})
        self.assertEqual(graph.edges, {1: [2, 3], 2: [1, 3], 3: [1, 2]})

if __name__ == '__main__':
    unittest.main()