class Node: pass

class Expression(Node): pass

class Constant(Node):
    def __init__(self, value):
        self.value = value

class BinaryExpression(Node):
    def __init__(self, left, right, operation):
        self.left = left
        self.right = right
        self.operation = operation

class Visitor:
    def visit(self, node):
        methodName = "visit_%s" % node.__class__.__name__
        method = getattr(self, methodName)
        method(node)

class CodeGenerator(Visitor):
    def visit_BinaryExpression(self, node):
        self.visit(node.left)
        self.visit(node.right)
        print(node.operation)

    def visit_Constant(self, node):
        print("push %s" % node.value)

# 2 + (4 * 3)
expression = BinaryExpression(
                Constant(2),
                BinaryExpression(
                    Constant(4),
                    Constant(3),
                    "multiply"),
                "add")

CodeGenerator().visit(expression)