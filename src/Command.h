#pragma once


class ICommand {};

class TagBeginBlock : ICommand {};

class TagEndBlock : ICommand {};

class TagStoreData : ICommand {};
