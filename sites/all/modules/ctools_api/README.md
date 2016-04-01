# CTools API

OOP representation for `content_types`, `styles` and `access` types of [CTools](https://www.drupal.org/project/ctools) plugins.

## Main features

- Interfaces. You'll never forget to implement something or doing this wrongly.
- Autoloading. `spl_autoload_register` takes everything on itself.
- Inheritance. No need explain benefits.
- Configuration. All forms builds on a one basis.
- Dependencies. The list of Drupal modules that should be enabled.
- Templatable. Auto creation of theme hooks and their variants.
- AJAX. Simpler than ever before.

## Examples

CTools API provide a set of useful plugins which also could be used as examples.

- Access
  - [HTTP Status Code](plugins/CTools/Plugins/Access/HTTPStatusCode.inc)
- Content types
  - [Entity Reference](plugins/CTools/Plugins/ContentTypes/EntityReference.inc)
- Styles
  - [Customizable Region](plugins/CTools/Plugins/Styles/CustomizableRegion.inc)
  - [Customizable Pane](plugins/CTools/Plugins/Styles/CustomizablePane.inc)

## Usage

Let module know about the objects. To do this, go to `*.info` file and add the next directive:

```ini
autoload[plugins][] = CTools
```

The key in `autoload` array is a subdirectory inside of the module directory and value - is a base namespace. As much as needed directories and namespace bases could be added by such way.

In simple words this means that all objects, namespace path of which starts from `CTools`, will be searched inside of `<MODULE_PATH>/plugins`.

## Autoloading for custom objects

If you have the objects and you want to use an autoloader for them, then just follow the information from [usage](#usage) section.
