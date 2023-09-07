#pragma once

class CloneableInterface {
public:
  virtual CloneableInterface *clone() const = 0;

  virtual ~CloneableInterface() = default;
};
