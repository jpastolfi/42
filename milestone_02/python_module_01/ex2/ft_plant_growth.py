class Plant:
    def __init__(self, name: str, height: int, age_days: int):
        self.name = name
        self.height = height
        self.age_days = age_days
        self.ratio = height / age_days

    def show(self):
        print("{}: {:.1f}cm, {} days old"
              .format(self.name, self.height, self.age_days))

    def grow(self):
        total_growth = 0
        for i in range(1, 8):
            total_growth += round(self.ratio, 1)
            print("=== Day {} ===".format(i))
            self.height = round(self.height + self.ratio, 1)
            self.age(1)
            self.show()
        print("Growth this week: {}cm".format(total_growth))

    def age(self, days: int):
        self.age_days += days


def ft_plant_growth():
    print("=== Garden Plant Growth ===")
    plant = Plant("Rose", 25, 30)
    plant.show()
    plant.grow()
