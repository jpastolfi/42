class Plant:
    class Statistics:
        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def display(self) -> None:
            print("Stats: {} grow, {} age, {} show"
                  .format(self.get_grow(), self.get_age(), self.get_show()))

        def get_grow(self) -> int:
            return self._grow_count

        def increment_grow(self) -> None:
            self._grow_count += 1

        def get_age(self) -> int:
            return self._age_count

        def increment_age(self) -> None:
            self._age_count += 1

        def get_show(self) -> int:
            return self._show_count

        def increment_show(self) -> None:
            self._show_count += 1

    def __init__(self, name: str, height: float, age_days: int) -> None:
        self._stats = self.Statistics()
        self._name = name
        self.set_name(name)
        if height < 0:
            print("{}: Error, height can't be negative"
                  .format(self.get_name()))
            return
        self._height = height
        if age_days < 0:
            print("{}: Error, age can't be negative"
                  .format(self.get_name()))
            return
        self._age_days = age_days
        if self._age_days == 0:
            self.ratio = 0.0
        else:
            self.ratio = self._height / self._age_days
        print("Plant created: ", end="")
        self.show()

    def get_name(self) -> str:
        return self._name

    def set_name(self, name: str) -> None:
        self._name = name

    def get_height(self) -> float:
        return self._height

    def set_height(self, height: float) -> None:
        if height < 0:
            print("""{}: Error, height can't be negative
Height update rejected""". format(self.get_name()))
        else:
            self._height = height
            print("Height updated: {}cm".format(self.get_height()))

    def get_age_days(self) -> int:
        return self._age_days

    def set_age_days(self, age_days: int) -> None:
        if age_days < 0:
            print("""{}: Error, age can't be negative
Age update rejected""". format(self.get_name()))
        else:
            self._age_days = age_days
            print("Age updated: {} days".format(self.get_age_days()))

    def show(self) -> None:
        self._stats.increment_show()
        print("{}: {:.1f}cm, {} days old"
              .format(self._name, self._height, self._age_days))

    def grow(self, times) -> None:
        total_growth = 0.0
        for i in range(1, times + 1):
            total_growth += round(self.ratio, 1)
            print("=== Day {} ===".format(i))
            self._height = round(self._height + self.ratio, 1)
            self.age(1)
            self.show()
        self._stats.increment_grow()
        print("Growth this week: {}cm".format(total_growth))

    def age(self, days: int) -> None:
        if days < 0:
            print("""{}: Error, age can't be negative
Age update rejected""". format(self.get_name()))
        self._age_days += days
        self._stats.increment_age()

    @staticmethod
    def is_older_than(days: int) -> None:
        print("Is {} days more than a year? -> {}"
              .format(days, True if days > 365 else False))

    @classmethod
    def create_anon_plant(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            color: str,
            has_bloomed: bool
            ) -> None:
        self.color = color
        self.has_bloomed = has_bloomed
        super().__init__(name, height, age_days)

    def bloom(self) -> None:
        print("[asking the {} to bloom]".format(self._name))
        self.has_bloomed = True

    def show(self) -> None:
        super().show()
        print("Color: {}".format(self.color))
        print(("{} has not bloomed yet" if not self.has_bloomed
               else "{} is blooming beautifully!")
              .format(self._name))


class Tree(Plant):
    class Statistics(Plant.Statistics):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def display(self) -> None:
            super().display()
            print("{} shade".format(self._shade_count))

        def get_shade(self) -> int:
            return self._shade_count

        def increment_shade(self) -> None:
            self._shade_count += 1

    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            trunk_diameter: float
            ) -> None:
        self._trunk_diameter = trunk_diameter
        super().__init__(name, height, age_days)
        self._stats: Tree.Statistics

    def produce_shade(self) -> None:
        self._stats.increment_shade()
        print("[asking the {} to produce shade]".format(self._name))
        print("Tree {} now produces a shade of {}cm long and {}cm wide."
              .format(self._name, self._height, self._trunk_diameter))

    def show(self) -> None:
        super().show()
        print("Trunk diameter: {}".format(self._trunk_diameter))


class Vegetable(Plant):
    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            harvest_season: str
            ) -> None:
        self._harvest_season = harvest_season
        self._nutrition_days = 0
        super().__init__(name, height, age_days)

    def nutritional_values(self, days: int) -> None:
        print("[make {} grow and age for {} days]"
              .format(self._name, days))
        self._age_days += days
        self._height += self._age_days
        self._nutrition_days += days

    def show(self):
        super().show()
        print("Harvest season: {}".format(self._harvest_season))
        print("Nutritional value: {}".format(self._nutrition_days))


class Seed(Flower):
    def __init__(
            self,
            name: str,
            height: float,
            age_days: int,
            color: str,
            has_bloomed: bool
            ) -> None:
        self._bloom_count = 0
        super().__init__(name, height, age_days, color, has_bloomed)

    def bloom(self) -> None:
        super().bloom()
        self._bloom_count += 1

    def show(self) -> None:
        super().show()
        print("Seeds: {}".format(self._bloom_count))


def display_stats(plant: Plant) -> None:
    plant._stats.display()


def main() -> None:
    print("=== Garden Statistics ===")
    print("=== Check year-old")
    Plant.is_older_than(30)
    Plant.is_older_than(400)

    Plant.create_anon_plant()

    print("\n=== Seed")
    seed = Seed("Sunflower", 80, 45, "yellow", False)
    seed.bloom()
    seed.show()
    seed.bloom()
    seed.show()

    print("=== Statistics")
    plant = Plant("Rose", 15, 10)
    plant._stats.display()
    plant.grow(1)
    plant._stats.display()
    plant.age(1)
    plant.show()
    plant._stats.display()

    print("=== Tree")
    tree = Tree("Oak", 200.0, 365, 5.0)
    tree.produce_shade()
    tree._stats.display()

    print("display_stats(seed): ", end="")
    display_stats(seed)
    print("display_stats(plant): ", end="")
    display_stats(plant)
    print("display_stats(tree): ", end="")
    display_stats(tree)


if (__name__ == "__main__"):
    main()
