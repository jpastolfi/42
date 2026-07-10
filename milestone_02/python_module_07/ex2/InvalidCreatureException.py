class InvalidCreatureException(Exception):
    def __init__(self, creature: str, strategy: str):
        super().__init__(
            f"Invalid Creature '{creature}' for {strategy} strategy"
        )
