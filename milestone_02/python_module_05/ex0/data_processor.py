import typing
from abc import ABC, abstractmethod

# ingest will process input data
# output will output ingested data

""" The validate method will be defined as validate(self, data: Any) -> bool
in the DataProcessor class. The overriding methods in the specialized classes will
share the same signature, as they cannot know what data will be sent and must accept any type. This method returns a bool that indicates if the provided data
can be ingested by this data processor. """

""" The ingest method will be defined as ingest(self, data: Any) -> None in the
DataProcessor class. The overriding methods in the specialized classes will have
their own specific signatures to match the types they expect. In case the user
does not validate the data before calling ingest, and provides invalid data, an
exception must be raised. """

class NotValidatedData(Exception):
    def init(self, message: str):
        super().message = message
        self.message = message

class DataProcessor(ABC):
    def __init__(self):
        self.data_list = []

    @abstractmethod
    def validate(self, data: any) -> bool:
        ...

    @abstractmethod
    def ingest(self, data: any) -> None:
        ...

    def output(self, amount: int) -> tuple[int, str]:
        if (amount > len(self.data_list)):
            print("Out of bounds")
            return
        print("Extracting {} value{}..."
            .format(amount, "s" if amount > 1 else ""))
        for i in range(amount):
            print("Value {}: {}".format(i, self.data_list.pop(0)))
        print("Remaining: {}".format(self.data_list))

class NumericProcessor(DataProcessor):
    def validate(self, data: any) -> bool:
        if isinstance(data, list):
            for item in data:
                print("Trying to validate input '{}': {}"
                    .format(item, isinstance(item, int | float)))
                if not isinstance(item, int | float):
                    self.data.remove(item)
        else:
            print("Trying to validate input '{}': {}"
                    .format(data, isinstance(data, int | float)))

    def ingest(self, data: int | float | list[int | float]) -> None:
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, int | float):
                    print("Got exception: Improper numeric data")
                else:
                    item = str(item)
        else:
            if not isinstance(data, int | float):
                    print("Got exception: Improper numeric data")
            else:
                data = str(data)


class TextProcessor(DataProcessor):
    def validate(self, data: any) -> bool:
        if isinstance(data, list):
            print("List")
        else:
            print("Not list")

    def ingest(self, data: str | list[str]) -> None:
        if isinstance(data, list):
            print("List")
        else:
            print("Not list")


class LogProcessor(DataProcessor):
    def validate(self, data: any) -> bool:
        if isinstance(data, list):
            print("List")
        else:
            print("Not list")

    def ingest(self, data: dict[str: str] | list[dict[str: str]]) -> None:
        if isinstance(data, list):
            print("List")
        else:
            print("Not list")

if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    numericProcessor = NumericProcessor()
    textProcessor = TextProcessor()
    logProcessor = LogProcessor()
    numericProcessor.validate(1)
    numericProcessor.validate([1, 2, 3, "a"])
    print(numericProcessor.data_list)
