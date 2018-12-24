// Automatically generated by the Fast Binary Encoding compiler, do not modify!
// https://github.com/chronoxor/FastBinaryEncoding
// Source: proto.fbe
// Version: 1.2.0.0

@file:Suppress("UnusedImport", "unused")

package proto.fbe

import java.io.*
import java.lang.*
import java.lang.reflect.*
import java.math.*
import java.nio.charset.*
import java.time.*
import java.util.*

import fbe.*
import proto.*

// Fast Binary Encoding Account field model
@Suppress("MemberVisibilityCanBePrivate", "RemoveRedundantCallsOfConversionMethods", "ReplaceGetOrSet")
class FieldModelAccount(buffer: Buffer, offset: Long) : FieldModel(buffer, offset)
{
    val id: FieldModelInt32 = FieldModelInt32(buffer, 4 + 4)
    val name: FieldModelString = FieldModelString(buffer, id.fbeOffset + id.fbeSize)
    val state: FieldModelState = FieldModelState(buffer, name.fbeOffset + name.fbeSize)
    val wallet: FieldModelBalance = FieldModelBalance(buffer, state.fbeOffset + state.fbeSize)
    val asset: FieldModelOptionalBalance = FieldModelOptionalBalance(buffer, wallet.fbeOffset + wallet.fbeSize)
    val orders: FieldModelVectorOrder = FieldModelVectorOrder(buffer, asset.fbeOffset + asset.fbeSize)

    // Field size
    override val fbeSize: Long = 4

    // Field body size
    val fbeBody: Long = (4 + 4
        + id.fbeSize
        + name.fbeSize
        + state.fbeSize
        + wallet.fbeSize
        + asset.fbeSize
        + orders.fbeSize
        )

    // Field extra size
    override val fbeExtra: Long get()
    {
        if ((_buffer.offset + fbeOffset + fbeSize) > _buffer.size)
            return 0

        val fbeStructOffset = readUInt32(fbeOffset).toLong()
        if ((fbeStructOffset == 0L) || ((_buffer.offset + fbeStructOffset + 4) > _buffer.size))
            return 0

        _buffer.shift(fbeStructOffset)

        val fbeResult = (fbeBody
            + id.fbeExtra
            + name.fbeExtra
            + state.fbeExtra
            + wallet.fbeExtra
            + asset.fbeExtra
            + orders.fbeExtra
            )

        _buffer.unshift(fbeStructOffset)

        return fbeResult
    }

    // Field type
    var fbeType: Long = fbeTypeConst

    companion object
    {
        const val fbeTypeConst: Long = 3
    }

    // Check if the struct value is valid
    fun verify(fbeVerifyType: Boolean = true): Boolean
    {
        if ((_buffer.offset + fbeOffset + fbeSize) > _buffer.size)
            return true

        val fbeStructOffset = readUInt32(fbeOffset).toLong()
        if ((fbeStructOffset == 0L) || ((_buffer.offset + fbeStructOffset + 4 + 4) > _buffer.size))
            return false

        val fbeStructSize = readUInt32(fbeStructOffset).toLong()
        if (fbeStructSize < (4 + 4))
            return false

        val fbeStructType = readUInt32(fbeStructOffset + 4).toLong()
        if (fbeVerifyType && (fbeStructType != fbeType))
            return false

        _buffer.shift(fbeStructOffset)
        val fbeResult = verifyFields(fbeStructSize)
        _buffer.unshift(fbeStructOffset)
        return fbeResult
    }

    // Check if the struct fields are valid
    fun verifyFields(fbeStructSize: Long): Boolean
    {
        var fbeCurrentSize = 4L + 4L

        if ((fbeCurrentSize + id.fbeSize) > fbeStructSize)
            return true
        if (!id.verify())
            return false
        fbeCurrentSize += id.fbeSize

        if ((fbeCurrentSize + name.fbeSize) > fbeStructSize)
            return true
        if (!name.verify())
            return false
        fbeCurrentSize += name.fbeSize

        if ((fbeCurrentSize + state.fbeSize) > fbeStructSize)
            return true
        if (!state.verify())
            return false
        fbeCurrentSize += state.fbeSize

        if ((fbeCurrentSize + wallet.fbeSize) > fbeStructSize)
            return true
        if (!wallet.verify())
            return false
        fbeCurrentSize += wallet.fbeSize

        if ((fbeCurrentSize + asset.fbeSize) > fbeStructSize)
            return true
        if (!asset.verify())
            return false
        fbeCurrentSize += asset.fbeSize

        if ((fbeCurrentSize + orders.fbeSize) > fbeStructSize)
            return true
        if (!orders.verify())
            return false
        fbeCurrentSize += orders.fbeSize

        return true
    }

    // Get the struct value (begin phase)
    fun getBegin(): Long
    {
        if ((_buffer.offset + fbeOffset + fbeSize) > _buffer.size)
            return 0

        val fbeStructOffset = readUInt32(fbeOffset).toLong()
        assert((fbeStructOffset > 0) && ((_buffer.offset + fbeStructOffset + 4 + 4) <= _buffer.size)) { "Model is broken!" }
        if ((fbeStructOffset == 0L) || ((_buffer.offset + fbeStructOffset + 4 + 4) > _buffer.size))
            return 0

        val fbeStructSize = readUInt32(fbeStructOffset).toLong()
        assert(fbeStructSize >= (4 + 4)) { "Model is broken!" }
        if (fbeStructSize < (4 + 4))
            return 0

        _buffer.shift(fbeStructOffset)
        return fbeStructOffset
    }

    // Get the struct value (end phase)
    fun getEnd(fbeBegin: Long)
    {
        _buffer.unshift(fbeBegin)
    }

    // Get the struct value
    fun get(fbeValue: Account = Account()): Account
    {
        val fbeBegin = getBegin()
        if (fbeBegin == 0L)
            return fbeValue

        val fbeStructSize = readUInt32(0).toLong()
        getFields(fbeValue, fbeStructSize)
        getEnd(fbeBegin)
        return fbeValue
    }

    // Get the struct fields values
    fun getFields(fbeValue: Account, fbeStructSize: Long)
    {
        var fbeCurrentSize = 4L + 4L

        if ((fbeCurrentSize + id.fbeSize) <= fbeStructSize)
            fbeValue.id = id.get()
        else
            fbeValue.id = 0
        fbeCurrentSize += id.fbeSize

        if ((fbeCurrentSize + name.fbeSize) <= fbeStructSize)
            fbeValue.name = name.get()
        else
            fbeValue.name = ""
        fbeCurrentSize += name.fbeSize

        if ((fbeCurrentSize + state.fbeSize) <= fbeStructSize)
            fbeValue.state = state.get(State.fromSet(EnumSet.of(State.initialized.value, State.bad.value)))
        else
            fbeValue.state = State.fromSet(EnumSet.of(State.initialized.value, State.bad.value))
        fbeCurrentSize += state.fbeSize

        if ((fbeCurrentSize + wallet.fbeSize) <= fbeStructSize)
            fbeValue.wallet = wallet.get()
        else
            fbeValue.wallet = Balance()
        fbeCurrentSize += wallet.fbeSize

        if ((fbeCurrentSize + asset.fbeSize) <= fbeStructSize)
            fbeValue.asset = asset.get()
        else
            fbeValue.asset = null
        fbeCurrentSize += asset.fbeSize

        if ((fbeCurrentSize + orders.fbeSize) <= fbeStructSize)
            orders.get(fbeValue.orders)
        else
            fbeValue.orders.clear()
        fbeCurrentSize += orders.fbeSize
    }

    // Set the struct value (begin phase)
    fun setBegin(): Long
    {
        assert((_buffer.offset + fbeOffset + fbeSize) <= _buffer.size) { "Model is broken!" }
        if ((_buffer.offset + fbeOffset + fbeSize) > _buffer.size)
            return 0

        val fbeStructSize = fbeBody
        val fbeStructOffset = _buffer.allocate(fbeStructSize) - _buffer.offset
        assert((fbeStructOffset > 0) && ((_buffer.offset + fbeStructOffset + fbeStructSize) <= _buffer.size)) { "Model is broken!" }
        if ((fbeStructOffset <= 0) || ((_buffer.offset + fbeStructOffset + fbeStructSize) > _buffer.size))
            return 0

        write(fbeOffset, fbeStructOffset.toUInt())
        write(fbeStructOffset, fbeStructSize.toUInt())
        write(fbeStructOffset + 4, fbeType.toUInt())

        _buffer.shift(fbeStructOffset)
        return fbeStructOffset
    }

    // Set the struct value (end phase)
    fun setEnd(fbeBegin: Long)
    {
        _buffer.unshift(fbeBegin)
    }

    // Set the struct value
    fun set(fbeValue: Account)
    {
        val fbeBegin = setBegin()
        if (fbeBegin == 0L)
            return

        setFields(fbeValue)
        setEnd(fbeBegin)
    }

    // Set the struct fields values
    fun setFields(fbeValue: Account)
    {
        id.set(fbeValue.id)
        name.set(fbeValue.name)
        state.set(fbeValue.state)
        wallet.set(fbeValue.wallet)
        asset.set(fbeValue.asset)
        orders.set(fbeValue.orders)
    }
}
