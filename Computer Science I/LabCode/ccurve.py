import turtle

"""
def cCurve(t,x,y,x2,y2,depth):
    def drawLine(t,x,y,x2,y2):
        t.up()
        t.goto(x,y)
        t.down()
        t.goto(x2,y2)

    if depth == 0:
        drawLine(t,x,y,x2,y2)
    else:
        xm = (x+x2+y-y2)/2
        ym = (x2+y+y2-x)/2
        cCurve(t,x,y,xm,ym,depth-1)
        cCurve(t,xm,ym,x2,y2,depth-1)
"""

def cCurve(t,length,depth):
    if depth == 0:
        t.forward(length)
    else:
        cCurve(t,length,depth-1)
        t.right(90)
        cCurve(t,length,depth-1)
        t.left(90)

def main():
    t = turtle.Turtle()
    turtle.tracer(10)
    #cCurve(t, 0,0,100,0, 12)
    t.right(90)
    t.up()
    t.goto(0,-5*30)
    t.down()
    cCurve(t,5,12)
    t.hideturtle()
    turtle.exitonclick()

main()
