from typing import List
from graph import Graph
from graphics import GraphicObject, Circle, Line
import svgwrite


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


class SvgVisualizer(Visualizer):
    def __init__(self):
        super().__init__()

    def draw(self, graphic_objects: List[GraphicObject]) -> svgwrite.Drawing:
        """Converts a list of GraphicObject instances to an SVG Drawing object.

        Args:
            graphic_objects: A list of GraphicObject instances.

        Returns:
            An svgwrite.Drawing object.
        """
        dwg = svgwrite.Drawing()
        for obj in graphic_objects:
            if obj.type == "circle":
                dwg.add(self._circle_to_svg(obj))
            elif obj.type == "line":
                dwg.add(self._line_to_svg(obj))
            # Add code to handle other types of GraphicObjects
        return dwg

    def write(self, filepath: str, graphic_objects: List[GraphicObject]):
        """Writes a list of GraphicObject instances to an SVG file.

        Args:
            filepath: The path to the output file.
            graphic_objects: A list of GraphicObject instances.
        """
        dwg = self.draw(graphic_objects)
        dwg.saveas(filepath)

    def _circle_to_svg(self, circle: Circle) -> svgwrite.shapes.Circle:
        """Converts a Circle instance to an SVG Circle object.

        Args:
            circle: A Circle instance.

        Returns:
            An svgwrite.shapes.Circle object.
        """
        x, y = circle.center
        r = circle.radius
        return svgwrite.shapes.Circle(center=(x, y), r=r)

    def _line_to_svg(self, line: Line) -> svgwrite.shapes.Line:
        """Converts a Line instance to an SVG Line object.

        Args:
            line: A Line instance.

        Returns:
            An svgwrite.shapes.Line object.
        """
        x1, y1 = line.start
        x2, y2 = line.end
        return svgwrite.shapes.Line(start=(x1, y1), end=(x2, y2), stroke='black')
