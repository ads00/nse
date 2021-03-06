/*! NSE
 * storage engine
 * model information are accessible compile time
 * nse::table<entity> : store entity defined in model
 *
 * Ex: nse::generic_table<movie> t;
 * t.add(a, b, c) // write runtime, structure info to write is compile time
 *
 * table management
 *  nse::generic_table<database_table> gt;
 *  gt.add<database_table<movie>>
 */

/*! NDB
 * Interface for sgbd compile time or runtime
 * query expressions use model fields objects : (mode.table.field [operator] model.table.field2)
 * expression is generated compile time (with constexpr objects)
 * query is executed runtime from static data of expression
 */

/*! MODEL
 * model tree is accessible compile time by Types only
 *
 */

/*! FIELD TYPES
 * field_link_id : link table line to 1 line from foreign table
 * Table_zeta
 * Table || id | name | Table_zeta_id | ...
 *
 * field_link_table : link table line to many line from foreign table
 * Table_zeta || id | ...
 * Table || id | ...
 * Link_Table_Table_zera || Table_id | Table_zeta_id
 */

// idea
// homogeneous table
/* add entity to each table on table.add
T1 size = 3
T2 size = 5
GLOBAL size = max of T1,T2
 */

m::table<sound>::field<NAME>::size();


ID | NAME | ID | NAME | DURATION
 -     -     1   test     45
