from typing import List
from graph import Graph
from graphics import GraphicObject, Circle, Line


class Visualizer:
    def __init__(self):
        pass

    def visualize(self, graph: Graph) -> List[GraphicObject]:
        """Generates a list of GraphicObject instances based on the given graph.

        Args:
            graph: A Graph object.

        Returns:
            A list of GraphicObject instances.
        """
        graphic_objects = []
        positions = {}
        for i, node in enumerate(graph.nodes):
            x = i * 30
            y = 50
            positions[node] = (x, y)
            graphic_objects.append(Circle((x, y), 10))
        for u, vs in graph.edges.items():
            for v in vs:
                graphic_objects.append(Line(positions[u], positions[v]))
        return graphic_objects
