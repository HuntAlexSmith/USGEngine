This project is for exploring the Entity-Component-System design pattern for game engines. Any overall notes will be thrown into here, but this will also include the basic links for what will be needed.

As it is a part of the name, there are three main parts to this:
[Entities](Entity)
[Components](Component)
[Systems](System)

The basic idea here is that Entities are purely just data containers that hold the different kind of Components that define the object. Then Systems are what iterate over components that Entities have in order to update the information.

An Example:
The Rendering System will iterate over the Transform Components to get the position, scale, and rotation for the object, as well as the Mesh Component to know what to render for the object. The Entities holding those components are what represent the singular Entity, usually represented by an Entities ID.

List of Libraries and APIs used will be [here](Libraries)

