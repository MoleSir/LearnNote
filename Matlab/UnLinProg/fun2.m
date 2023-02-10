%此文件为非线性约束的条件
%要求所有不等式为.... <= 0
%此函数返回一个矩阵，第一个是非线性不等式的矩阵，第二个是非线性等式的矩阵
function [g,h] = fun2(x)
    g = [-x(1)^2 + x(2) - x(3)^2     x(1)+x(2)^2 + x(3)^3 - 20];
    h = [-x(1) - x(2)^2 + 2          x(2) + 2*x(3)^2 - 3];
end
