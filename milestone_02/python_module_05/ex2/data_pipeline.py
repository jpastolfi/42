from typing import Any
from abc import ABC, abstractmethod


class NotValidatedData(Exception):
    ...


class DataProcessor(ABC):
    def __init__(self):
        self.validated_data = []
        self.processed_data = []
        self.current_item = -1
        self.count = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        ...

    @abstractmethod
    def ingest(self, data: Any) -> None:
        ...

    def output(self) -> tuple[int, str]:
        self.current_item += 1
        return (self.current_item, self.processed_data.pop(0))


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        is_valid: bool
        if isinstance(data, list):
            for item in data:
                if isinstance(item, int | float):
                    is_valid = True
                else:
                    is_valid = False
        else:
            if isinstance(data, int | float):
                is_valid = True
            else:
                is_valid = False
        return (is_valid)

    def ingest(self, data: int | float | list[int | float]) -> None:
        try:
            if isinstance(data, list):
                for item in data:
                    if not isinstance(item, int | float):
                        raise NotValidatedData("Improper numeric data")
                    else:
                        self.processed_data.append(str(item))
                        self.count += 1
            else:
                if not isinstance(data, int | float):
                    raise NotValidatedData("Improper numeric data")
                else:
                    self.processed_data.append(str(data))
                    self.count += 1
        except NotValidatedData as e:
            print("Got exception: {}".format(e))
        except Exception as e:
            print("Got exception: {}".format(e))

    def __str__(self):
        return "NumericProcessor"

class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        is_valid: bool
        if isinstance(data, list):
            for item in data:

                if isinstance(item, str):
                    self.validated_data.append(item)
                    is_valid = True
                else:
                    is_valid = False
        else:
            if isinstance(data, str):
                self.validated_data.append(data)
                is_valid = True
            else:
                is_valid = False
        return (is_valid)

    def ingest(self, data: str | list[str]) -> None:
        try:
            if isinstance(data, list):
                for item in data:
                    if not isinstance(item, str):
                        raise NotValidatedData("Improper string data")
                    else:
                        self.processed_data.append(item)
                        self.count += 1
            else:
                if not isinstance(data, str):
                    raise NotValidatedData("Improper string data")
                else:
                    self.processed_data.append(data)
                    self.count += 1
        except NotValidatedData as e:
            print("Got exception: {}".format(e))
        except Exception as e:
            print("Got exception: {}".format(e))

    def __str__(self):
        return "TextProcessor"

class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        is_valid: bool
        if isinstance(data, list):
            for item in data:

                if (isinstance(item, dict)):
                    for unit in list(item.items()):
                        k, v = unit
                        if isinstance(k, str) and isinstance(v, str):
                            self.validated_data.append(item)
                            is_valid = True
                        else:
                            is_valid = False
                else:
                    is_valid = False
        else:
            if (isinstance(data, dict)):
                for unit in list(data.items()):
                    k, v = unit
                    if isinstance(k, str) and isinstance(v, str):
                        self.validated_data.append(data)
                        is_valid = True
                    else:
                        is_valid = False
            else:
                is_valid = False
        return is_valid

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        try:
            if isinstance(data, list):
                for item in data:
                    if not isinstance(item, dict):
                        raise NotValidatedData("Improper dictionary")
                    else:
                        for unit in list(item.items()):
                            k, v = unit
                            if (not isinstance(k, str)
                                    or not isinstance(v, str)):
                                raise NotValidatedData("Improper dictionary")
                        self.processed_data.append(str(item))
                        self.count += 1
            else:
                if (isinstance(data, dict)):
                    for unit in list(data.items()):
                        k, value = unit
                        if (not isinstance(k, str)
                                or not isinstance(value, str)):
                            raise NotValidatedData("Improper dictionary")
                        else:
                            self.processed_data.append(str(data))
                            self.count += 1
                else:
                    raise NotValidatedData("Improper dictionary")
        except NotValidatedData as e:
            print("Got exception: {}".format(e))
        except Exception as e:
            print("Got exception: {}".format(e))

    def __str__(self):
        return "LogProcessor"

class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...

class DataStream():
    def __init__(self):
        self.processor_list = []

    def register_processor(self, proc: DataProcessor) -> None:
        if (isinstance(proc, NumericProcessor)):
            print("Registering Numeric Processor...")
            self.processor_list.append(proc)
            print("Numeric processor registered successfully!")
        elif (isinstance(proc, TextProcessor)):
            print("Registering Text Processor...")
            self.processor_list.append(proc)
            print("Text processor registered successfully!")
        elif (isinstance(proc, LogProcessor)):
            print("Registering Log Processor...")
            self.processor_list.append(proc)
            print("Log processor registered successfully!")
        else:
            print("Unknown DataProcessor object")

    def process_stream(self, stream: list[Any]) -> None:
        try:
            print("Send batch of data on stream: {}".format(stream))
            is_processed:bool = False
            for item in stream:
                for processor in self.processor_list:
                    if (processor.validate(item)):
                        is_processed = True
                        processor.ingest(item)
                if not is_processed:
                    print("Item {} has no matching processor".format(item))
                is_processed = False
        except Exception as e:
            print("Got exception: {}".format(e))

    def print_processors_stats(self) -> None:
        for processor in self.processor_list:
            print("{} has {} items to process.".format(processor, processor.count))
            while processor.processed_data:
                index, value = processor.output()
                print("{} {} remaining in processor"
                    .format(
                        processor.count - processor.current_item,
                        "items" if processor.count - processor.current_item > 1 else "item"
                        ))
                print("Value {}: {}".format(index, value))

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        ...


if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===")
    data_stream = DataStream()
    numeric_processor = NumericProcessor()
    text_processor = TextProcessor()
    log_processor = LogProcessor()
    data_stream.register_processor(numeric_processor)
    data_stream.register_processor(text_processor)
    data_stream.register_processor(log_processor)
    data_stream.process_stream([
        'Hello world',
        [3.14, -1, 2.71],
        [
            {'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'},
            {'log_level': 'INFO', 'log_message': 'User wil is connected'}
        ],
        42,
        ['Hi', 'five']
    ])
    data_stream.print_processors_stats()