#ifndef TAG_CONTROLLER_H
#define TAG_CONTROLLER_H

#include "rclcpp/rclcpp.hpp"
#include "rviz_common/properties/property.hpp"
#include "rviz_common/properties/string_property.hpp"
#include "tag_property.hpp"
#include "node_property.hpp"

namespace topological_rviz_tools
{

class NodeProperty;
  
/** @brief Property specialized to provide getter for booleans. */
class TagController: public rviz_common::properties::Property
{

public:
  TagController(const QString& name = QString(),
		const std::vector<std::string>& default_value = std::vector<std::string>(),
		const QString& description = QString(),
		NodeProperty* parent = 0,
		const char *changed_slot = 0,
		QObject* receiver = 0);

  virtual ~TagController();
  /** @brief Do all setup that can't be done in the constructor.
   *
   *
   * Calls onInitialize() just before returning. */
  void initialize();

  /** @brief Subclasses should call this whenever a change is made which would change the results of toString(). */
  void emitConfigChanged();

  virtual void load(const rviz_common::Config& config);
  virtual void save(rviz_common::Config config) const;

  // required by something that initialises this class
  QString formatClassId(const QString& class_id);

  /** @brief Return the class identifier which was used to create this
   * instance.  This version just returns whatever was set with
   * setClassId(). */
  virtual QString getClassId() const { return class_id_; }

  /** @brief Set the class identifier used to create this instance.
   * Typically this will be set by the factory object which created it. */
  virtual void setClassId( const QString& class_id ) { class_id_ = class_id; }

Q_SIGNALS:
  void configChanged();

private:

  QString class_id_;
  rclcpp::Logger logger_{rclcpp::get_logger("rviz2")};
};

} // end namespace topological_rviz_tools

#endif // TAG_CONTROLLER_H
