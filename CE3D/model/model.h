// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_MODEL_H
#define CE3D_MODEL_MODEL_H

#include "CE3D/util/stdinc.h"

#include <string>
#include <boost/container/vector.hpp>

#include "CE3D/util/CE3D_vector.h"
#include "CE3D/transformation/itransformable.h"
#include "CE3D/model/vertex.h"

namespace CE3D
{

/**
 * TODO
 */
template <typename MaterialType>
class Model : public Transformation::ITransformable
{
private:
    /**
     * All vectors used for this model.
     */
    boost::container::vector<Vector> m_Vectors;
    /**
     * The vertices.
     */
    boost::container::vector<Vertex<MaterialType> > m_Vertices;
    /**
     * True if the model is visible.
     */
    bool m_Visible;
    /**
     * A not necessarily unique name.
     */
    std::string m_Name;
public:
    Model();

    /**
     * Gets the visibility of the model.
     *
     * @return The visibility state. true if visible, false if not.
     */
    bool
    IsVisible() const
    { return m_Visible; }

    /**
     * Sets the visibility of the model.
     *
     * @param value: The visibility state. true if visible, false if not.
     */
    void
    SetVisibility(bool const value)
    { m_Visible = value; }

    /**
     * Gets the name of the model.
     *
     * @return The name.
     */
    std::string
    GetName() const
    { return m_Name; }

    /**
     * Sets the name of the model.
     *
     * @param value: The name to set.
     */
    void
    SetName(std::string const value)
    { m_Name = value; }

    // Inherited documentation comment
    virtual void
    Transform(Transformation::Transformation const& matrix) override;

    // Inherited documentation comment
    virtual void
    Translate(Transformation::Translation const& translation) override;

    // Inherited documentation comment
    virtual void
    Scale(const ModelDataType factor) override;

    // Inherited documentation comment
    virtual void
    Scale(Transformation::Scale const& scale) override;

    // Inherited documentation comment
    virtual void
    Rotate(Transformation::Rotation const& rotation) override;

    /**
     * Getter (const).
     *
     * @return a list of all vectors of this model (const)
     */
    boost::container::vector<Vector> const&
    GetVectors() const
    { return m_Vectors; }
    /**
     * Getter.
     *
     * @return a list of all vectors of this model
     */
    boost::container::vector<Vector>&
    GetVectors()
    { return m_Vectors; }

    /**
     * Getter.
     *
     * @return a list of all vertices in this model
     */
    boost::container::vector<Vertex<MaterialType> >&
    GetVertices()
    { return m_Vertices; }

    /**
     * Getter (const).
     *
     * @return a list of all vertices in this model (const)
     */
    boost::container::vector<Vertex<MaterialType> > const&
    GetVertices() const
    { return m_Vertices; }

};

}

#include "CE3D/model/model_code.h"

#endif /* CE3D_MODEL_MODEL_H */
