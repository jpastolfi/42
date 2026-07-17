from pydantic import BaseModel, Field


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)  # 3-10 characters
    name: str = Field(min_length=1, max_length=50)  # 1-50 characters
    crew_size: int = Field(ge=1, le=20)  # 1-20 people
    power_level: float = Field(ge=0.0, le=100.0)  # 0.0-100.0 percent
    oxygen_level: float = Field(ge=0.0, le=100.0)  # 0.0-100.0 percent
    last_maintenance: str  # DateTime field
    is_operational: bool = True
    notes: str = Field(max_length=200)  # Optional string max 200 characters


def main():
    teste = SpaceStation(station_id="Jpapa")
    print(teste)


if __name__ == "__main__":
    main()
