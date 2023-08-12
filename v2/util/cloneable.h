#pragma once

class ClonableInterface {
public:
  virtual ClonableInterface *clone() const = 0;

  virtual ~ClonableInterface() = default;
};
