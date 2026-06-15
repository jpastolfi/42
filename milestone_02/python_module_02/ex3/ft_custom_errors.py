class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        self.message = message
        super().__init__(self.message)

    def __str__(self) -> str:
        return f"Error: {self.message}"


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error") -> None:
        super().__init__(message)


def test_specific_errors(error_id: int) -> None:
    print("Testing GardenError...")
    try:
        match error_id:
            case 0:
                raise PlantError
            case 1:
                raise WaterError("Water error")
            case _:
                print("None")
    except PlantError as e:
        print(f"Caught {e.message}: The tomato plant is wilting!")

    except WaterError as e:
        print(f"Caught {e.message}: Not enough water in the tank!")


def test_parent_error() -> None:
    try:
        raise PlantError("Plant error!")
    except GardenError:
        print("This is a General GardenError")


if (__name__ == "__main__"):
    print("=== Custom Garden Errors Demo ===")
    for i in range(0, 2):
        test_specific_errors(i)
    test_parent_error()
