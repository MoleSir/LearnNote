from Meal import *

# 创建食物builder
mealBuilder = MealBuilder()

# 取餐
vegMeal = mealBuilder.GetVegMeal()
nonvegMeal = mealBuilder.GetNonVegMeal()

# 显示
vegMeal.ShowItems()
nonvegMeal.ShowItems()
