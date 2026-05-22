class Plant:
    def __init__(self, name, height, age_days):
        self.name = name
        self.height = height
        self.age_days = age_days
    
    def show(self):
        print("{}: {}cm, {} days old".format(self.name, self.height, self.age_days))

def ft_garden_data():
    plant_one = Plant("Rose", "25", "30")
    plant_two = Plant("Sunflower", "80", "45")
    plant_three = Plant("Cactus", "15", "120")
    print("=== Garden Plant Registry ===")
    plant_one.show()
    plant_two.show()
    plant_three.show()

ft_garden_data()