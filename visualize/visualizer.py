import math
from typing import List
from graph import Graph
from graphics import GraphicObject, Circle, Line, Arrow
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
            x = 80 + i * 30
            y = 50
            positions[node] = (x, y)
            graphic_objects.append(Circle((x, y), 10))
        edges = []
        for u, vs in graph.edges.items():
            for v in vs:
                if graph.directed or (u <= v and not graph.directed):
                    edges.append((u, v))
        for u, v in edges:
            if graph.directed:
                graphic_objects.append(Arrow(positions[u], positions[v]))
            else:
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
        self.dwg = svgwrite.Drawing()
        for obj in graphic_objects:
            if obj.type == "circle":
                self._circle_to_svg(obj)
            elif obj.type == "line":
                self._line_to_svg(obj)
            elif obj.type == "arrow":
                self._arrow_to_svg(obj)
            # Add code to handle other types of GraphicObjects
        return self.dwg

    def write(self, filepath: str, graphic_objects: List[GraphicObject]):
        """Writes a list of GraphicObject instances to an SVG file.

        Args:
            filepath: The path to the output file.
            graphic_objects: A list of GraphicObject instances.
        """
        self.draw(graphic_objects)
        self.dwg.saveas(filepath)

    def _circle_to_svg(self, circle: Circle) -> svgwrite.shapes.Circle:
        """Converts a Circle instance to an SVG Circle object.

        Args:
            circle: A Circle instance.

        Returns:
            An svgwrite.shapes.Circle object.
        """
        x, y = circle.center
        r = circle.radius
        obj = svgwrite.shapes.Circle(center=(x, y), r=r)
        self.dwg.add(obj)
        return obj

    def _line_to_svg(self, line: Line) -> svgwrite.shapes.Line:
        """Converts a Line instance to an SVG Line object.

        Args:
            line: A Line instance.

        Returns:
            An svgwrite.shapes.Line object.
        """
        x1, y1 = line.start
        x2, y2 = line.end
        obj = svgwrite.shapes.Line(start=(x1, y1), end=(x2, y2), stroke="black")
        self.dwg.add(obj)
        return obj

    def _arrow_to_svg(self, arrow: Arrow) -> List[svgwrite.base.BaseElement]:
        """Converts an Arrow instance to an SVG Line object with an arrowhead.
        Args:
            arrow: An Arrow instance.

        Returns:
            An svgwrite.shapes.Line object with an arrowhead."""
        x1, y1 = arrow.start
        x2, y2 = arrow.end
        line = svgwrite.shapes.Line(start=(x1, y1), end=(x2, y2), stroke="black")
        arrowhead_length = 10  # Change this value to adjust the size of the arrowhead
        # Calculate the angle of the line
        angle = math.atan2(y2 - y1, x2 - x1)
        # Calculate the coordinates of the end of the arrowhead
        x3 = x2 - arrowhead_length * math.cos(angle + math.pi / 6)
        y3 = y2 - arrowhead_length * math.sin(angle + math.pi / 6)
        x4 = x2 - arrowhead_length * math.cos(angle - math.pi / 6)
        y4 = y2 - arrowhead_length * math.sin(angle - math.pi / 6)
        # Add a polygon to the drawing to represent the arrowhead
        arrowhead = svgwrite.shapes.Polygon(
            points=[(x2, y2), (x3, y3), (x4, y4)], stroke="black", fill="black"
        )
        objects = [line, arrowhead]
        self.dwg.add(line)
        self.dwg.add(arrowhead)
        return objects
