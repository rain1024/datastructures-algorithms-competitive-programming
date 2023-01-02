class GraphicObject:
    def __init__(self, type, **kwargs):
        self.type = type
        self.kwargs = kwargs

class Circle(GraphicObject):
    def __init__(self, center, radius, **kwargs):
        super().__init__("circle", **kwargs)
        self.center = center
        self.radius = radius

class Rectangle(GraphicObject):
    def __init__(self, top_left, bottom_right, **kwargs):
        super().__init__("rectangle", **kwargs)
        self.top_left = top_left
        self.bottom_right = bottom_right

class Line(GraphicObject):
    def __init__(self, start, end, **kwargs):
        super().__init__("line", **kwargs)
        self.start = start
        self.end = end

class Arrow(GraphicObject):
    def __init__(self, start, end, **kwargs):
        super().__init__("arrow", **kwargs)
        self.start = start
        self.end = end

class Text(GraphicObject):
    def __init__(self, text, position, **kwargs):
        super().__init__("text", **kwargs)
        self.text = text
        self.position = position