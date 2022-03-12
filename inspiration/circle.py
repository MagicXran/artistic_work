import math
import turtle
from turtle import *


class Interpolation:

    def __init__(self, P: list, arc: tuple):
        """
        默认圆心(0,0)
        :param P: 随机一点
        :param arc: (x,y,r,angle)
        """
        self.point = [(P[0], P[1])]
        self.P = P
        self.Fi = 0
        self.arc = arc
        self.R = arc[2]
        self.F_delta = 0
        self.quadrant = 1
        self.step = abs(P[0] - arc[0]) + abs(P[1] - arc[1])  # math.fabs(P[0] - arc[0]) + math.fabs(P[1] - arc[1])
        self.anticlockwise = 1  # 默认逆时针
        # self.Judge_quadrant()
        # self.Calc_Fi()
        pass

    def Calc_Fi(self):
        self.Fi = math.pow(self.P[0], 2) + math.pow(self.P[1], 2) - math.pow(self.R, 2)
        return self.Fi

    def forward_backward(self):
        #   逆时针
        if self.anticlockwise == 1:
            # 第一象限
            if self.quadrant == 1:
                if self.Fi >= 0:
                    self.P[0] = self.P[0] - 1
                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi - 2 * self.P[0] + 1
                else:
                    self.P[1] = self.P[1] + 1

                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi + 2 * self.P[1] + 1

            if self.quadrant == 2:
                if self.Fi >= 0:

                    self.P[1] = self.P[1] - 1
                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi - 2 * self.P[1] + 1
                else:
                    self.P[0] = self.P[0] - 1
                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi - 2 * self.P[0] + 1

            if self.quadrant == 3:
                if self.Fi >= 0:
                    self.P[0] = self.P[0] + 1

                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi + 2 * self.P[0] + 1
                else:
                    self.P[1] = self.P[1] - 1

                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi - 2 * self.P[1] - 1
            if self.quadrant == 4:
                if self.Fi >= 0:
                    self.P[1] = self.P[1] + 1

                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi + 2 * self.P[1] + 1
                else:
                    self.P[0] = self.P[0] + 1

                    self.point.append((self.P[0], self.P[1]))
                    self.Fi = self.Fi + 2 * self.P[0] + 1

    def judge_quadrant(self):
        """
        判断点P所在象限
        :return:
        """
        if (self.P[0] > 0) and (self.P[1] >= 0):
            self.quadrant = 1
        elif (self.P[0] <= 0) and (self.P[1] > 0):
            self.quadrant = 2
        elif (self.P[0] < 0) and (self.P[1] <= 0):
            self.quadrant = 3
        else:
            self.quadrant = 4
        pass

    def run(self):
        self.Calc_Fi()
        while self.step > 1:
            self.judge_quadrant()
            self.forward_backward()
            # print(self.step, self.Fi, self.quadrant)
            print(self.point, self.Fi, self.step)
            self.step = self.step - 1


# 画出坐标轴
def axis(turtle):
    s = Screen()
    s.setworldcoordinates(-4, -4, 4, 4)
    turtle.speed(0)
    s.delay(0)
    turtle.goto(-200, 0)
    for i in range(-200, 200):
        turtle.write(i, False, "right", ("Arial", 12, "normal"))
        turtle.fd(20)
    turtle.stamp()
    turtle.write("x", False, "center", ("Arial", 20, "normal"))
    turtle.penup()
    turtle.goto(0, -4)
    turtle.pendown()
    turtle.left(90)
    for i in range(-4, 4):
        turtle.write(i, False, "right", ("Arial", 12, "normal"))
        turtle.fd(1)
    turtle.write("y", False, "center", ("Arial", 20, "normal"))
    turtle.stamp()
    turtle.penup()  # turtle.hideturtle()


def draw_coordinate():
    turtle.penup()
    turtle.goto(0, 250)
    turtle.pendown()
    turtle.goto(0, -250)
    turtle.penup()
    turtle.goto(250, 0)
    turtle.pendown()
    turtle.goto(-250, 0)
    turtle.penup()


def main():
    # draw_coordinate()
    # axis(turtle)
    draw_coordinate()
    P = (60, 60)
    obj = Interpolation(list(P), (0, 0, 70, 90))  # calc_Fi(P)
    obj.run()  # turtle.circle(70)

    turtle.color('black')
    turtle.penup()
    turtle.goto(obj.point[0])
    turtle.pendown()

    for i in obj.point:
        turtle.goto(i)
    turtle.done()


if __name__ == '__main__':
        main()
